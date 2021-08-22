#pragma once

#include <unordered_map>

#include "deck.h"

enum class ESuit {
  NONE     = 0,
  HEARTS   = 1 << 0,
  DIAMONDS = 1 << 1,
  CROSSES  = 1 << 2,
  SPADES   = 1 << 3,
  SHAMA    = (1 << 0) + (1 << 1) + (1 << 2) + (1 << 3)
};

class Deck;
class Card {
  public:
  friend Deck;
  Card(const Card&& other);
  const std::u32string& name() const;
  int8_t value() const;
  int8_t points() const;
  ESuit suit() const;

  static const std::unordered_map<int, std::string> SuitToColor;

  private:
  Card(std::u32string name, int8_t value, int8_t points, ESuit suit) :
      _name(name), _value(value), _points(points), _suit(suit) {}
  Card(const Card&) = delete;
  Card& operator=(Card&) = delete;

  Card& operator=(Card&&);

  std::u32string _name;
  int8_t _value;
  int8_t _points;
  ESuit _suit;
};

std::ostream& operator<<(std::ostream& os, const Card& card);
