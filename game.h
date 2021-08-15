#pragma once
#include <iostream>
#include <memory>
#include <optional>
#include <vector>

#include "player.h"

enum class EGameModes { PlayerX1, BotsOnly };

class Game {
  public:
  Game(EGameModes mode, std::istream& is, std::ostream& os);
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

  void renderTable() const;
  void renderFaceDown() const;
  void renderSpace(size_t count) const;
  std::vector<std::unique_ptr<Player>> players;
  std::istream& input;
  std::ostream& output;
  int score_t1;
  int score_t2;
  int lastTake;
  ESuit trump;
  std::vector<std::pair<bool, std::vector<std::unique_ptr<Card>>>> table;
};
