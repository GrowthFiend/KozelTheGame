#pragma once

#include <iostream>
#include <string>

auto char_utf32_to_utf8(char32_t utf32, const char *buffer) -> char *;

auto operator<<(std::ostream &os, const char32_t *s) -> std::ostream &;

auto operator<<(std::ostream &os, const std::u32string &s) -> std::ostream &;
