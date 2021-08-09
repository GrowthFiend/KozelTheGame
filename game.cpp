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
}

void Game::Start() {
  while (score_t1 < 12 || score_t2 < 12) { playMatch(); }
}

void Game::playMatch() {}
