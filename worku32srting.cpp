#include "worku32srting.hpp"
#include <cstddef>
#include <cstdint>

void char_utf32_to_utf8(char32_t utf32, std::array<char, BUFF_SIZE> &buffer) {
  constexpr uint32_t UN_1MAX = 0x7F;
  constexpr uint32_t UN_2MAX = 0x7FF;
  constexpr uint32_t UN_3MAX = 0x10000;
  constexpr uint32_t UN_4MAX = 0x110000;
  constexpr uint8_t OFFSET6 = 6;
  constexpr uint8_t OFFSET12 = 12;
  constexpr uint8_t OFFSET18 = 18;
  constexpr uint32_t UN_2 = 0b1100'0000;
  constexpr uint32_t UN_3 = 0b1110'0000;
  constexpr uint32_t UN_4 = 0b1111'0000;
  constexpr uint32_t UN_X = 0b1000'0000;
  constexpr uint32_t UN_BM = 0b0011'1111;

  int8_t i = 0;
  if (utf32 < UN_1MAX) {
    buffer[i++] = static_cast<char>(utf32);
  } else if (utf32 < UN_2MAX) {
    buffer[i++] = static_cast<char>(UN_2 + (utf32 >> OFFSET6));
    buffer[i++] = static_cast<char>(UN_X + (utf32 & UN_BM));
  } else if (utf32 < UN_3MAX) {
    buffer[i++] = static_cast<char>(UN_3 + (utf32 >> OFFSET12));
    buffer[i++] = static_cast<char>(UN_X + ((utf32 >> OFFSET6) & UN_BM));
    buffer[i++] = static_cast<char>(UN_X + (utf32 & UN_BM));
  } else if (utf32 < UN_4MAX) {
    buffer[i++] = static_cast<char>(UN_4 + (utf32 >> OFFSET18));
    buffer[i++] = static_cast<char>(UN_X + ((utf32 >> OFFSET12) & UN_BM));
    buffer[i++] = static_cast<char>(UN_X + ((utf32 >> OFFSET6) & UN_BM));
    buffer[i++] = static_cast<char>(UN_X + (utf32 & UN_BM));
  }
  buffer[i] = '\0';
}

std::ostream &operator<<(std::ostream &os, const char32_t *s) {
  std::array<char, BUFF_SIZE> buff{0};
  char_utf32_to_utf8(*s, buff);
  os << buff.data();
  return os;
}

std::ostream &operator<<(std::ostream &os, const std::u32string &s) {
  for (char32_t i : s) {
    os << &i;
  }
  return os;
}