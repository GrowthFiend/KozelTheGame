#pragma once
#include <set>
#include <string>

#include "card.h"

class Player {
  public:
  Player(const std::string& name) : _name(name) {};

  private:
  std::string _name;
  std::set<Card> hand;
};

class User : public Player {
  public:
  User(const std::string& name) : Player(name) {};
};

class Bot : public Player {
  public:
  Bot(const std::string& name) : Player(name) {};
};
