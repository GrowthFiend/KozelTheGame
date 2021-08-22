#include "card.h"

#include "worku32srting.h"

const std::unordered_map<int, std::string> Card::SuitToColor {
    {static_cast<int>(ESuit::HEARTS), "\x1b[31;47m"},
    {static_cast<int>(ESuit::DIAMONDS), "\x1b[31;1;47m"},
    {static_cast<int>(ESuit::CROSSES), "\x1b[30;1;47m"},
    {static_cast<int>(ESuit::SPADES), "\x1b[30;47m"},
    {static_cast<int>(ESuit::SHAMA), "\x1b[30;47m"},
};

const std::u32string& Card::name() const { return _name; }

int8_t Card::value() const { return _value; }

int8_t Card::points() const { return _points; }

ESuit Card::suit() const { return _suit; }

Card::Card(const Card&& other) :
    _name(std::move(other.name())),
    _value(std::move(other.value())),
    _points(std::move(other.points())),
    _suit(std::move(other.suit())) {}

std::ostream& operator<<(std::ostream& os, const Card& card) {
  os << Card::SuitToColor.at(static_cast<int>(card.suit()));
  os << card.name() << ' ';
  os << "\x1b[0m";
  os << ' ';
  return os;
}
