#pragma once

#include <cstdint>
#include <iostream>
#include <memory>
#include <optional>
#include <vector>

#include "card.hpp"
#include "iuserinterface.hpp"
#include "player.hpp"

const uint8_t HAND_MAX = 4;
const uint8_t TEAM_COUNT = 2;
const uint8_t PLAYERS_BY_TEAM = 2;
constexpr uint8_t PLAYER_COUNT = TEAM_COUNT * PLAYERS_BY_TEAM;
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
  void chooseTrump();
  void showWinner() const;
  void showTable() const;
  bool isEndMatchTurn();
  bool TryEarlyTurn();
  [[nodiscard]] std::optional<size_t> playerWithGenerals() const;
  [[nodiscard]] std::optional<size_t> playerWithSnotty() const;
  [[nodiscard]] std::vector<size_t> playersWithFlushOr41() const;

  int score_t1;
  int score_t2;
  int lastTake;
  Deck deck;
  ESuit trump = ESuit::ANY_SUIT;
  Players players;
  Stake stake;

  std::unique_ptr<IUserInterface> ui;
};
