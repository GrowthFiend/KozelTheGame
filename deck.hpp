#pragma once

#include <memory>
#include <optional>
#include <vector>

#include "card.hpp"

constexpr int8_t CARD_MAX = 36;
constexpr int8_t VALUE_6 = 0;
constexpr int8_t VALUE_7 = 1;
constexpr int8_t VALUE_8 = 2;
constexpr int8_t VALUE_9 = 3;
constexpr int8_t VALUE_J = 4;
constexpr int8_t VALUE_Q = 5;
constexpr int8_t VALUE_K = 6;
constexpr int8_t VALUE_T = 7;
constexpr int8_t VALUE_A = 8;
constexpr int8_t VALUE_S = 18;
constexpr int8_t POINT_0 = 0;
constexpr int8_t POINT_J = 2;
constexpr int8_t POINT_Q = 3;
constexpr int8_t POINT_K = 4;
constexpr int8_t POINT_T = 10;
constexpr int8_t POINT_A = 11;

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
