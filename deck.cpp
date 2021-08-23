#include "deck.h"

#include <algorithm>
#include <random>

Deck::Deck() {
  cards.push_back(std::make_unique<Card>(Card {18, 0, ESuit::ANY_SUIT}));
  cards.push_back(std::make_unique<Card>(Card {1, 0, ESuit::SPADES}));
  cards.push_back(std::make_unique<Card>(Card {2, 0, ESuit::SPADES}));
  cards.push_back(std::make_unique<Card>(Card {3, 0, ESuit::SPADES}));
  cards.push_back(std::make_unique<Card>(Card {4, 2, ESuit::SPADES}));
  cards.push_back(std::make_unique<Card>(Card {5, 3, ESuit::SPADES}));
  cards.push_back(std::make_unique<Card>(Card {6, 4, ESuit::SPADES}));
  cards.push_back(std::make_unique<Card>(Card {7, 10, ESuit::SPADES}));
  cards.push_back(std::make_unique<Card>(Card {8, 11, ESuit::SPADES}));
  cards.push_back(std::make_unique<Card>(Card {0, 0, ESuit::HEARTS}));
  cards.push_back(std::make_unique<Card>(Card {1, 0, ESuit::HEARTS}));
  cards.push_back(std::make_unique<Card>(Card {2, 0, ESuit::HEARTS}));
  cards.push_back(std::make_unique<Card>(Card {3, 0, ESuit::HEARTS}));
  cards.push_back(std::make_unique<Card>(Card {4, 2, ESuit::HEARTS}));
  cards.push_back(std::make_unique<Card>(Card {5, 3, ESuit::HEARTS}));
  cards.push_back(std::make_unique<Card>(Card {6, 4, ESuit::HEARTS}));
  cards.push_back(std::make_unique<Card>(Card {7, 10, ESuit::HEARTS}));
  cards.push_back(std::make_unique<Card>(Card {8, 11, ESuit::HEARTS}));
  cards.push_back(std::make_unique<Card>(Card {0, 0, ESuit::DIAMONDS}));
  cards.push_back(std::make_unique<Card>(Card {1, 0, ESuit::DIAMONDS}));
  cards.push_back(std::make_unique<Card>(Card {2, 0, ESuit::DIAMONDS}));  //
  cards.push_back(std::make_unique<Card>(Card {3, 0, ESuit::DIAMONDS}));
  cards.push_back(std::make_unique<Card>(Card {4, 2, ESuit::DIAMONDS}));
  cards.push_back(std::make_unique<Card>(Card {5, 3, ESuit::DIAMONDS}));
  cards.push_back(std::make_unique<Card>(Card {6, 4, ESuit::DIAMONDS}));  //
  cards.push_back(std::make_unique<Card>(Card {7, 10, ESuit::DIAMONDS}));
  cards.push_back(std::make_unique<Card>(Card {8, 11, ESuit::DIAMONDS}));
  cards.push_back(std::make_unique<Card>(Card {0, 0, ESuit::CROSSES}));
  cards.push_back(std::make_unique<Card>(Card {1, 0, ESuit::CROSSES}));  //
  cards.push_back(std::make_unique<Card>(Card {2, 0, ESuit::CROSSES}));
  cards.push_back(std::make_unique<Card>(Card {3, 0, ESuit::CROSSES}));
  cards.push_back(std::make_unique<Card>(Card {4, 2, ESuit::CROSSES}));
  cards.push_back(std::make_unique<Card>(Card {5, 3, ESuit::CROSSES}));  //
  cards.push_back(std::make_unique<Card>(Card {6, 4, ESuit::CROSSES}));
  cards.push_back(std::make_unique<Card>(Card {7, 10, ESuit::CROSSES}));
  cards.push_back(std::make_unique<Card>(Card {8, 11, ESuit::CROSSES}));
}

void Deck::Shuffle(size_t seed) {
  std::random_device rd;
  std::mt19937_64 g(rd());
  g.seed(seed);
  std::shuffle(cards.begin(), cards.end(), g);
}

const std::unique_ptr<Card>& Deck::ShowCard(size_t pos) const { return cards[pos]; }

std::optional<std::unique_ptr<Card>> Deck::GiveOne() {
  if (cards.size()) {
    std::unique_ptr<Card> temp = std::move(cards.back());
    cards.pop_back();
    return temp;
  }
  return {};
}

size_t Deck::Size() const { return cards.size(); }
