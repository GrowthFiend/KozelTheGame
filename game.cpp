#include "game.h"

Game::Game(EGameModes mode, IRenderSystem& rs) : score_t1(0), score_t2(0), lastTake(0), render(rs) {
  switch (mode) {
    case EGameModes::PlayerX1: {
      players.push_back(std::make_unique<Player>(User(render.AskUserName())));
      break;
    }
    case EGameModes::BotsOnly: players.push_back(std::make_unique<Player>(Bot("Bogey"))); break;
    default: break;
  }
  players.push_back(std::make_unique<Player>(Bot("Screem")));
  players.push_back(std::make_unique<Player>(Bot("Bully")));
  players.push_back(std::make_unique<Player>(Bot("Sleepy")));
  table.reserve(4);
}

void Game::Start() {
  while (score_t1 < 12 && score_t2 < 12) { playMatch(); }
  showWinner();
}

void Game::playMatch() {
  renderTable();
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

void Game::showWinner() const {
  output << "Team" << (score_t2 < score_t1) + 1 << " win!" << std::endl;
}

void Game::dealCards() {
  for (size_t i = 0; i < 4; ++i) {
    for (size_t j = 0; j < 4; ++j) {
      players[(j + lastTake + (Deck::GetInstance().Size() > (36 - 4 * 4))) % 4]->TakeOneCard();
      renderTable();
    }
  }
}

std::vector<std::pair<bool, std::vector<std::unique_ptr<Card>>>>& Game::getTable() { return table; }

void Game::showTrump() {
  bool isAce = false;
  do {
    const auto& x = Deck::GetInstance().ShowCard(Deck::GetInstance().Size() / 4 + rand() % 9);
    output << "trump is " << *x << std::endl;
    trump = x->suit();
    if (x->points() == 11) {
      isAce = true;
      output << "Never believe in Ace!" << std::endl;
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
          players[(playerNum + i) % 4]->PlayFourCard(i, getTable());
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
    if (players[(i + lastTake) % 4]->HasFlushOr41()) { res.push_back((i + lastTake) % 4); }
  }
  return res;
}
