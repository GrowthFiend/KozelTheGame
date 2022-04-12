#pragma once

#include <string>

#include "deck.hpp"

class Player {
public:
  Player(const std::string &name) : _name(name){};
  void TakeOneCard(Deck &deck);
  bool HasGenerals() const;
  bool HasSnotty() const;
  bool HasFlush() const;
  bool Has41() const;
  bool WantEarlyPlay() const;
  void PlayFourCard(size_t orderNum,
                    std::vector<std::pair<bool, std::vector<Card>>> &stake);
  const std::vector<Card> &getHand() const;

private:
  std::string _name;
  std::vector<Card> hand;
};

class User : public Player {
public:
  User(const std::string &name) : Player(name){};
};

class Bot : public Player {
public:
  Bot(const std::string &name) : Player(name){};
};

using Players = std::vector<std::unique_ptr<Player>>;
