#pragma once

#include <memory>
#include <optional>
#include <vector>

#include "card.h"

using Stake = std::vector<std::pair<bool, std::vector<std::unique_ptr<Card>>>>;

class Deck {
  public:
  Deck();
  Deck(const Deck&) = delete;
  Deck& operator=(Deck&) = delete;
  Deck(const Deck&&)     = delete;
  Deck& operator=(Deck&&) = delete;

  void Shuffle(size_t seed);
  const std::unique_ptr<Card>& ShowCard(size_t pos) const;
  std::optional<std::unique_ptr<Card>> GiveOne();
  size_t Size() const;
  ~Deck() {};

  private:
  std::vector<std::unique_ptr<Card>> cards;
};
