#include "card.h"

const std::unordered_map<int, std::string> Card::SuitToColor {
    {static_cast<int>(ESuit::HEARTS), "\x1b[31;47m"},
    {static_cast<int>(ESuit::DIAMONDS), "\x1b[31;1;47m"},
    {static_cast<int>(ESuit::CROSSES), "\x1b[30;1;47m"},
    {static_cast<int>(ESuit::SPADES), "\x1b[30;47m"},
    {static_cast<int>(ESuit::SHAMA), "\x1b[30;47m"},
};

char* char_utf32_to_utf8(char32_t utf32, const char* buffer)
// Encodes the UTF-32 encoded char into a UTF-8 string.
// Stores the result in the buffer and returns the position
// of the end of the buffer
// (unchecked access, be sure to provide a buffer that is big enough)
{
  char* end = const_cast<char*>(buffer);
  if (utf32 < 0x7F) *(end++) = static_cast<unsigned>(utf32);
  else if (utf32 < 0x7FF) {
    *(end++) = 0b1100'0000 + static_cast<unsigned>(utf32 >> 6);
    *(end++) = 0b1000'0000 + static_cast<unsigned>(utf32 & 0b0011'1111);
  } else if (utf32 < 0x10000) {
    *(end++) = 0b1110'0000 + static_cast<unsigned>(utf32 >> 12);
    *(end++) = 0b1000'0000 + static_cast<unsigned>((utf32 >> 6) & 0b0011'1111);
    *(end++) = 0b1000'0000 + static_cast<unsigned>(utf32 & 0b0011'1111);
  } else if (utf32 < 0x110000) {
    *(end++) = 0b1111'0000 + static_cast<unsigned>(utf32 >> 18);
    *(end++) = 0b1000'0000 + static_cast<unsigned>((utf32 >> 12) & 0b0011'1111);
    *(end++) = 0b1000'0000 + static_cast<unsigned>((utf32 >> 6) & 0b0011'1111);
    *(end++) = 0b1000'0000 + static_cast<unsigned>(utf32 & 0b0011'1111);
  }
  *end = '\0';
  return end;
}

std::ostream& operator<<(std::ostream& os, const char32_t* s) {
  const char buffer[5] {0};  // That's the famous "big-enough buffer"
  while (s && *s) {
    char_utf32_to_utf8(*(s++), buffer);
    os << buffer;
  }
  return os;
}

std::ostream& operator<<(std::ostream& os, const std::u32string& s) { return (os << s.c_str()); }

std::ostream& operator<<(std::ostream& os, const Card& card) {
  os << Card::SuitToColor.at(static_cast<int>(card.suit()));
  os << card.name() << ' ';
  os << "\x1b[0m";
  os << ' ';
  return os;
}

const std::u32string& Card::name() const { return _name; }

int8_t Card::value() const { return _value; }

int8_t Card::points() const { return _points; }

ESuit Card::suit() const { return _suit; }

Card::Card(const Card&& other) :
    _name(std::move(other.name())),
    _value(std::move(other.value())),
    _points(std::move(other.points())),
    _suit(std::move(other.suit())) {}
