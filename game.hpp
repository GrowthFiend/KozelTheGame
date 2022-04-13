#pragma once

#include <iostream>
#include <memory>
#include <optional>
#include <vector>

#include "card.hpp"
#include "iuserinterface.hpp"
#include "player.hpp"

const uint8_t HAND_MAX = 4;
const uint8_t PLAYER_COUNT = 4;
const uint8_t SCORE_TO_WIN = 12;
const uint8_t SCORE_FOR_GENERAL = 12;
const uint8_t SCORE_FOR_SNOTTY = 6;
const uint32_t STEP_TIME = 200'000;
const uint32_t STEP_TIMEX5 = 1'000'000;

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
  auto isEndMatchTurn() -> bool;
  auto TryEarlyTurn() -> bool;
  [[nodiscard]] auto playerWithGenerals() const -> std::optional<size_t>;
  [[nodiscard]] auto playerWithSnotty() const -> std::optional<size_t>;
  [[nodiscard]] auto playersWithFlushOr41() const -> std::vector<size_t>;

  int score_t1;
  int score_t2;
  int lastTake;
  Deck deck;
  ESuit trump = ESuit::ANY_SUIT;
  Players players;
  Stake stake;

  std::unique_ptr<IUserInterface> ui;
};
