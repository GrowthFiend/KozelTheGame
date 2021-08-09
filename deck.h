#pragma once

#include <memory>
#include <optional>
#include <vector>

#include "card.h"
class Card;
class Deck {
  public:
  static Deck& GetInstance() {
    static Deck instance;
    return instance;
  }
  void Shuffle(size_t seed);
  void PrintCards(std::ostream& os);
  std::optional<std::unique_ptr<Card>> GiveOne();
  ~Deck() {};

  private:
  Deck();
  Deck(const Deck&) = delete;
  Deck& operator=(Deck&) = delete;
  Deck(const Deck&&)     = delete;
  Deck& operator=(Deck&&) = delete;
  std::vector<std::unique_ptr<Card>> cards;
};
