#include "worku32srting.h"

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
