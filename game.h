#pragma once
#include <iostream>
#include <memory>
#include <vector>

#include "player.h"

enum class EGameModes { PlayerX1, BotsOnly };

class Game {
  public:
  Game(EGameModes mode, std::istream& is, std::ostream& os);
  void Start();

  private:
  void playMatch();
  std::vector<std::unique_ptr<Player>> players;
  std::istream& input;
  std::ostream& output;
  uint8_t score_t1;
  uint8_t score_t2;
  uint8_t lastTake;
};
