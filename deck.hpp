#pragma once

#include <memory>
#include <optional>
#include <vector>

#include "card.hpp"

using Stake = std::vector<std::pair<bool, std::vector<Card>>>;

class Deck {
public:
  Deck();
  Deck(const Deck &) = delete;
  Deck &operator=(Deck &) = delete;
  Deck(const Deck &&) = delete;
  Deck &operator=(Deck &&) = delete;

  void Shuffle(size_t seed);
  const Card &ShowCard(size_t pos) const;
  std::optional<Card> GiveOne();
  size_t Size() const;
  ~Deck() = default;

private:
  std::vector<Card> cards;
};
