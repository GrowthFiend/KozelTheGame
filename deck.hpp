#pragma once

#include <memory>
#include <optional>
#include <vector>

#include "card.hpp"

const int8_t CARD_MAX = 36;
const int8_t VALUE_6 = 0;
const int8_t VALUE_7 = 1;
const int8_t VALUE_8 = 2;
const int8_t VALUE_9 = 3;
const int8_t VALUE_J = 4;
const int8_t VALUE_Q = 5;
const int8_t VALUE_K = 6;
const int8_t VALUE_T = 7;
const int8_t VALUE_A = 8;
const int8_t VALUE_S = 18;
const int8_t POINT_0 = 0;
const int8_t POINT_J = 2;
const int8_t POINT_Q = 3;
const int8_t POINT_K = 4;
const int8_t POINT_T = 10;
const int8_t POINT_A = 11;

using Stake = std::vector<std::pair<bool, std::vector<Card>>>;

class Deck {
public:
  Deck();
  Deck(const Deck &) = delete;
  Deck &operator=(Deck &) = delete;
  Deck(const Deck &&) = delete;
  Deck &operator=(Deck &&) = delete;
  ~Deck() = default;

  void Shuffle(size_t seed);
  [[nodiscard]] const Card &ShowCard(size_t pos) const;
  std::optional<Card> GiveOne();
  [[nodiscard]] size_t Size() const;

private:
  std::vector<Card> cards;
};
