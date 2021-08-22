#include "card.h"

int8_t Card::value() const { return _value; }

int8_t Card::points() const { return _points; }

ESuit Card::suit() const { return _suit; }

Card::Card(const Card&& other) :
    _value(std::move(other.value())),
    _points(std::move(other.points())),
    _suit(std::move(other.suit())) {}
