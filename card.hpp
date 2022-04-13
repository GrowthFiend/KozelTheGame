#pragma once
#include <memory>

enum ESuit {
  NONE = 0,
  HEARTS = 1 << 0,
  DIAMONDS = 1 << 1,
  CROSSES = 1 << 2,
  SPADES = 1 << 3,
  ANY_SUIT = HEARTS | DIAMONDS | CROSSES | SPADES
};
class Deck;
class Card {
public:
  friend Deck;
  Card(int8_t value, int8_t points, ESuit suit);
  Card(Card &&other) noexcept;
  Card &operator=(Card &&other) noexcept;
  Card(const Card &) = delete;
  Card &operator=(Card &) = delete;
  ~Card() = default;

  [[nodiscard]] int8_t value() const;
  [[nodiscard]] int8_t points() const;
  [[nodiscard]] ESuit suit() const;

private:
  int8_t _value;
  int8_t _points;
  ESuit _suit;
};

bool operator<(const Card &lhs, const Card &rhs);
