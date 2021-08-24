#include "card.h"

#include <iostream>
#include <tuple>

Card::Card(Card &&other) : _value(other._value), _points(other._points), _suit(other._suit) {
  other._value  = -1;
  other._points = -1;
  other._suit   = ESuit::NONE;
}

Card &Card::operator=(Card &&other) {
  if (&other == this) return *this;

  _value  = other._value;
  _points = other._points;
  _suit   = other._suit;

  other._value  = -1;
  other._points = -1;
  other._suit   = ESuit::NONE;

  return *this;
}

int8_t Card::value() const { return _value; }

int8_t Card::points() const { return _points; }

ESuit Card::suit() const { return _suit; }

bool operator<(const Card &lhs, const Card &rhs) {
  return std::make_tuple(lhs.suit(), lhs.value(), lhs.points()) <
         std::make_tuple(rhs.suit(), rhs.value(), rhs.points());
}
