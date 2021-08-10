#include "game.h"

Game::Game(EGameModes mode, std::istream& is, std::ostream& os) :
    input(is), output(os), score_t1(0), score_t2(0), lastTake(0) {
  switch (mode) {
    case EGameModes::PlayerX1: {
      output << "Please, enter youre name: ";
      std::string username;
      input >> username;
      players.push_back(std::make_unique<Player>(User(username)));
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
  //проверить на досрочные ходы
  //сделать очередные ходы
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
  score_t1 = 12;
  //вернуть карты в колоду
}

void Game::showWinner() const {
  output << "Team" << (score_t2 > score_t1) + 1 << " win!" << std::endl;
}

void Game::dealCards() {
  for (size_t i = 0; i < 4; ++i) {
    for (size_t j = 0; j < 4; ++j) {
      players[(j + lastTake + (Deck::GetInstance().Size() > (36 - 4 * 4))) % 4]->TakeOneCard();
      renderTable();
    }
  }
}

void Game::renderTable() const {
  //str1
  renderSpace(2);
  for (size_t i = 4; i != 0; --i) {
    if (players[2]->getHand().size() < i) renderSpace(1);
    else
      renderFaceDown();
  }
  renderSpace(2);
  output << score_t1 << ':' << score_t2;
  output << std::endl;

  //str2
  renderSpace(8);
  output << std::endl;

  //str3
  if (players[1]->getHand().size() < 1) renderSpace(1);
  else
    renderFaceDown();
  renderSpace(1);
  renderFaceDown();
  output << Deck::GetInstance().Size() << ' ';
  renderSpace(3);
  if (players[3]->getHand().size() < 4) renderSpace(1);
  else
    renderFaceDown();
  output << std::endl;

  //str4
  if (players[1]->getHand().size() < 2) renderSpace(1);
  else
    renderFaceDown();
  renderSpace(1);
  for (size_t i = 1; i <= 4; ++i) {
    if (table[0].size() < i) renderSpace(1);
    else
      renderFaceDown();
  }
  renderSpace(1);
  if (players[3]->getHand().size() < 3) renderSpace(1);
  else
    renderFaceDown();
  output << std::endl;

  //str5
  if (players[1]->getHand().size() < 3) renderSpace(1);
  else
    renderFaceDown();
  renderSpace(1);
  for (size_t i = 1; i <= 4; ++i) {
    if (table[1].size() < i) renderSpace(1);
    else
      renderFaceDown();
  }
  renderSpace(1);
  if (players[3]->getHand().size() < 2) renderSpace(1);
  else
    renderFaceDown();
  output << std::endl;

  //str6
  if (players[1]->getHand().size() < 4) renderSpace(1);
  else
    renderFaceDown();
  renderSpace(1);
  for (size_t i = 1; i <= 4; ++i) {
    if (table[2].size() < i) renderSpace(1);
    else
      renderFaceDown();
  }
  renderSpace(1);
  if (players[3]->getHand().size() < 1) renderSpace(1);
  else
    renderFaceDown();
  output << std::endl;

  //str7
  renderSpace(2);

  for (size_t i = 1; i <= 4; ++i) {
    if (table[3].size() < i) renderSpace(1);
    else
      renderFaceDown();
  }
  renderSpace(2);
  output << std::endl;

  //str8
  renderSpace(2);
  size_t i = 4;
  for (const auto& card : players[0]->getHand()) {
    output << *card;
    --i;
  }
  while (i--) { renderSpace(1); }
  output << std::endl;

  //str8
  output << "------------------------" << std::endl;
}

void Game::renderFaceDown() const {
  output << "\x1b[35;47m";
  output << U"\x1F0A0" << ' ';
  output << "\x1b[0m";
  output << ' ';
}

void Game::renderSpace(size_t count) const {
  while (count--) output << "   ";
}

void Game::showTrump() {
  const auto& x = Deck::GetInstance().ShowCard(Deck::GetInstance().Size() / 4 + rand() % 9);
  output << "trump is " << *x << std::endl;
  trump = x->suit();
}
