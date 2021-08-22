#pragma once
#include <iostream>
#include <memory>
#include <optional>
#include <vector>

#include "irendersystem.h"
#include "player.h"

enum class EGameModes { PlayerX1, BotsOnly };

class Game {
  public:
  Game(EGameModes mode, IRenderSystem& rs);
  void Start();

  private:
  void playMatch();
  void showWinner() const;
  void dealCards();
  void showTrump();
  bool isEndMatchTurn();
  bool TryEarlyTurn();
  std::optional<size_t> playerWithGenerals() const;
  std::optional<size_t> playerWithSnotty() const;
  std::vector<size_t> playersWithFlushOr41() const;

  std::vector<std::pair<bool, std::vector<std::unique_ptr<Card>>>>& getTable();

  int score_t1;
  int score_t2;
  int lastTake;
  ESuit trump;
  std::vector<std::unique_ptr<Player>> players;
  std::vector<std::pair<bool, std::vector<std::unique_ptr<Card>>>> table;

  IRenderSystem render;
};
