#include "game.h"

Game::Game(EGameModes mode, std::unique_ptr<IUserInterface>&& userInterface) :
    score_t1(0), score_t2(0), lastTake(0), ui(std::move(userInterface)) {
  switch (mode) {
    case EGameModes::PlayerX1: {
      players.push_back(std::make_unique<Player>(User(ui->AskUserName())));
      break;
    }
    case EGameModes::BotsOnly: players.push_back(std::make_unique<Player>(Bot("Bogey"))); break;
    default: break;
  }
  players.push_back(std::make_unique<Player>(Bot("Screem")));
  players.push_back(std::make_unique<Player>(Bot("Bully")));
  players.push_back(std::make_unique<Player>(Bot("Sleepy")));
  stake.reserve(4);
  stake[0].second.reserve(5);
  stake[1].second.reserve(5);
  stake[2].second.reserve(5);
  stake[3].second.reserve(5);
}

void Game::Start() {
  while (score_t1 < 12 && score_t2 < 12) { playMatch(); }
  showWinner();
}

void Game::playMatch() {
  showTable();
  //  deck.Shuffle(185);
  dealCards();
  showTrump();
  if (isEndMatchTurn()) {
    //показать!
    return;
  }
  TryEarlyTurn();
  //забрать взятку

  //пока есть что добирать
  //добрать недостающие карты в зависимости от того, кто побил
  //проверить на досрочные ходы
  //сделать очередные ходы
  //забрать взятку

  //пока есть карты в руке
  //сделать очередные ходы
  //забрать взятку

  //посчитать общую взятку и начислить очки
  score_t2 = 12;
  //вернуть карты в колоду
}

void Game::showWinner() const { ui->RenderWinner((score_t2 < score_t1) + 1); }

void Game::showTable() const { ui->RenderTable(players, stake, deck, score_t1, score_t2); }

void Game::dealCards() {
  for (size_t i = 0; i < 4; ++i) {
    for (size_t j = 0; j < 4; ++j) {
      players[(j + lastTake + (deck.Size() > (36 - 4 * 4))) % 4]->TakeOneCard(deck);
      showTable();
    }
  }
}

void Game::showTrump() {
  bool isAce = false;
  do {
    const auto& x = deck.ShowCard(deck.Size() / 4 + rand() % 9);
    ui->TrumpIs(x);
    trump = x.suit();
    if (x.points() == 11) {
      isAce = true;
      ui->NeverBeliveInAce();
    } else
      isAce = false;
    usleep(1000000);
  } while (isAce);
}

bool Game::isEndMatchTurn() {
  if (playerWithGenerals().has_value()) {
    playerWithGenerals().value() % 2 ? score_t1 += 12 : score_t2 += 12;
    return true;
  }

  if (playerWithSnotty().has_value()) {
    playerWithSnotty().value() % 2 ? score_t1 += 6 : score_t2 += 6;
    return true;
  }
  return false;
}

bool Game::TryEarlyTurn() {
  auto earlyPlayers = playersWithFlushOr41();
  if (!earlyPlayers.empty()) {
    for (const auto& playerNum : earlyPlayers) {
      if (players[playerNum]->WantEarlyPlay()) {
        for (size_t i = 0; i < 4; ++i) {
          players[(playerNum + i) % 4]->PlayFourCard(i, stake);
          showTable();
        }
        return true;
      }
    }
  }
  return false;
}

std::optional<size_t> Game::playerWithGenerals() const {
  for (size_t i = 0; i < 4; ++i) {
    if (players[i]->HasGenerals()) { return i; }
  }
  return {};
}

std::optional<size_t> Game::playerWithSnotty() const {
  for (size_t i = 0; i < 4; ++i) {
    if (players[i]->HasSnotty()) { return i; }
  }
  return {};
}

std::vector<size_t> Game::playersWithFlushOr41() const {
  std::vector<size_t> res;
  for (size_t i = 0; i < 4; ++i) {
    if (players[(i + lastTake) % 4]->HasFlush() || players[(i + lastTake) % 4]->Has41()) {
      res.push_back((i + lastTake) % 4);
    }
  }
  return res;
}
