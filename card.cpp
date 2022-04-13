#include "card.hpp"

#include <tuple>

Card::Card(int8_t value, int8_t points, ESuit suit)
    : _value(value), _points(points), _suit(suit) {}

Card::Card(Card &&other) noexcept
    : _value(other._value), _points(other._points), _suit(other._suit) {
  other._value = -1;
  other._points = -1;
  other._suit = ESuit::NONE;
}

auto Card::operator=(Card &&other) noexcept -> Card & {
  if (&other == this) {
    return *this;
  }

  _value = other._value;
  _points = other._points;
  _suit = other._suit;

  other._value = -1;
  other._points = -1;
  other._suit = ESuit::NONE;

  return *this;
}

auto Card::value() const -> int8_t { return _value; }

auto Card::points() const -> int8_t { return _points; }

auto Card::suit() const -> ESuit { return _suit; }

auto operator<(const Card &lhs, const Card &rhs) -> bool {
  return std::make_tuple(lhs.suit(), lhs.value(), lhs.points()) <
         std::make_tuple(rhs.suit(), rhs.value(), rhs.points());
}
