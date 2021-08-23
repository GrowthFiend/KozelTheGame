#pragma once
#include <memory>

enum ESuit {
  NONE     = 0,
  HEARTS   = 1 << 0,
  DIAMONDS = 1 << 1,
  CROSSES  = 1 << 2,
  SPADES   = 1 << 3,
  ANY_SUIT = HEARTS | DIAMONDS | CROSSES | SPADES
};

class Card {
  public:
  Card(const Card&& other);
  Card(int8_t value, int8_t points, ESuit suit) : _value(value), _points(points), _suit(suit) {}
  int8_t value() const;
  int8_t points() const;
  ESuit suit() const;

  private:
  Card(const Card&) = delete;
  Card& operator=(Card&) = delete;

  Card& operator=(Card&&);

  int8_t _value;
  int8_t _points;
  ESuit _suit;
};
