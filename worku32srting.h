#pragma once

#include <iostream>
#include <string>

char *char_utf32_to_utf8(char32_t utf32, const char *buffer);

std::ostream &operator<<(std::ostream &os, const char32_t *s);

std::ostream &operator<<(std::ostream &os, const std::u32string &s);
