#pragma once

#include <iostream>
#include <memory>
#include <optional>
#include <vector>

#include "iuserinterface.hpp"
#include "player.hpp"

enum class EGameModes { PlayerX1, BotsOnly };

class Game {
public:
  Game(EGameModes mode, std::unique_ptr<IUserInterface> &&userInterface);
  void Start();

private:
  void playMatch();
  void dealCards();
  void showTrump();
  void showWinner() const;
  void showTable() const;
  bool isEndMatchTurn();
  bool TryEarlyTurn();
  std::optional<size_t> playerWithGenerals() const;
  std::optional<size_t> playerWithSnotty() const;
  std::vector<size_t> playersWithFlushOr41() const;

  int score_t1;
  int score_t2;
  int lastTake;
  Deck deck;
  ESuit trump;
  Players players;
  Stake stake;

  std::unique_ptr<IUserInterface> ui;
};
