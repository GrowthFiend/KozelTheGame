#pragma once

#include <array>
#include <iostream>
#include <string>

constexpr uint8_t BUFF_SIZE = 5;

void char_utf32_to_utf8(char32_t utf32, std::array<char, BUFF_SIZE> &buff);

std::ostream &operator<<(std::ostream &os, const char32_t *s);

std::ostream &operator<<(std::ostream &os, const std::u32string &s);