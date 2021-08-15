#pragma once
#include <set>
#include <string>

#include "deck.h"

class Player {
  public:
  Player(const std::string& name) : _name(name) {};
  void TakeOneCard();
  bool HasGenerals() const;
  bool HasSnotty() const;
  bool HasFlushOr41() const;
  bool WantEarlyPlay() const;
  void PlayFourCard(
      size_t orderNum, std::vector<std::pair<bool, std::vector<std::unique_ptr<Card>>>>& table);
  const std::set<std::unique_ptr<Card>>& getHand() const;

  private:
  std::string _name;
  std::set<std::unique_ptr<Card>> hand;
};

class User : public Player {
  public:
  User(const std::string& name) : Player(name) {};
};

class Bot : public Player {
  public:
  Bot(const std::string& name) : Player(name) {};
};
