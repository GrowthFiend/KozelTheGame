#pragma once

#include <string>
#include <utility>

#include "deck.hpp"

const uint8_t FORTY = 40;
const uint8_t FORTY_MINUS_SHAMA = 29;
class Player {
public:
  explicit Player(std::string name) : _name(std::move(name)){};
  void TakeOneCard(Deck &deck);
  [[nodiscard]] auto HasGenerals() const -> bool;
  [[nodiscard]] auto HasSnotty() const -> bool;
  [[nodiscard]] auto HasFlush() const -> bool;
  [[nodiscard]] auto Has41() const -> bool;
  static auto WantEarlyPlay() -> bool;
  void PlayFourCard(size_t orderNum,
                    std::vector<std::pair<bool, std::vector<Card>>> &stake);
  [[nodiscard]] auto getHand() const -> const std::vector<Card> &;

private:
  std::string _name;
  std::vector<Card> hand;
};

class User : public Player {
public:
  explicit User(const std::string &name) : Player(name){};
};

class Bot : public Player {
public:
  explicit Bot(const std::string &name) : Player(name){};
};

using Players = std::vector<std::unique_ptr<Player>>;
