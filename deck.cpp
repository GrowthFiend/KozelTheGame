#include "deck.hpp"

#include <algorithm>
#include <mutex>
#include <random>

Deck::Deck() {
  cards.reserve(CARD_MAX);
  cards.push_back(std::move(Card{VALUE_S, POINT_0, ESuit::ANY_SUIT}));
  cards.push_back(std::move(Card{VALUE_7, POINT_0, ESuit::SPADES}));
  cards.push_back(std::move(Card{VALUE_8, POINT_0, ESuit::SPADES}));
  cards.push_back(std::move(Card{VALUE_9, POINT_0, ESuit::SPADES}));
  cards.push_back(std::move(Card{VALUE_J, POINT_J, ESuit::SPADES}));
  cards.push_back(std::move(Card{VALUE_Q, POINT_Q, ESuit::SPADES}));
  cards.push_back(std::move(Card{VALUE_K, POINT_K, ESuit::SPADES}));
  cards.push_back(std::move(Card{VALUE_T, POINT_T, ESuit::SPADES}));
  cards.push_back(std::move(Card{VALUE_A, POINT_A, ESuit::SPADES}));
  cards.push_back(std::move(Card{VALUE_6, POINT_0, ESuit::HEARTS}));
  cards.push_back(std::move(Card{VALUE_7, POINT_0, ESuit::HEARTS}));
  cards.push_back(std::move(Card{VALUE_8, POINT_0, ESuit::HEARTS}));
  cards.push_back(std::move(Card{VALUE_9, POINT_0, ESuit::HEARTS}));
  cards.push_back(std::move(Card{VALUE_J, POINT_J, ESuit::HEARTS}));
  cards.push_back(std::move(Card{VALUE_Q, POINT_Q, ESuit::HEARTS}));
  cards.push_back(std::move(Card{VALUE_K, POINT_K, ESuit::HEARTS}));
  cards.push_back(std::move(Card{VALUE_T, POINT_T, ESuit::HEARTS}));
  cards.push_back(std::move(Card{VALUE_A, POINT_A, ESuit::HEARTS}));
  cards.push_back(std::move(Card{VALUE_6, POINT_0, ESuit::DIAMONDS}));
  cards.push_back(std::move(Card{VALUE_7, POINT_0, ESuit::DIAMONDS}));
  cards.push_back(std::move(Card{VALUE_8, POINT_0, ESuit::CROSSES})); //
  cards.push_back(std::move(Card{VALUE_9, POINT_0, ESuit::DIAMONDS}));
  cards.push_back(std::move(Card{VALUE_J, POINT_J, ESuit::DIAMONDS}));
  cards.push_back(std::move(Card{VALUE_Q, POINT_Q, ESuit::DIAMONDS}));
  cards.push_back(std::move(Card{VALUE_K, POINT_K, ESuit::CROSSES})); //
  cards.push_back(std::move(Card{VALUE_T, POINT_T, ESuit::DIAMONDS}));
  cards.push_back(std::move(Card{VALUE_A, POINT_A, ESuit::DIAMONDS}));
  cards.push_back(std::move(Card{VALUE_6, POINT_0, ESuit::CROSSES}));
  cards.push_back(std::move(Card{VALUE_7, POINT_0, ESuit::CROSSES})); //
  cards.push_back(std::move(Card{VALUE_8, POINT_0, ESuit::CROSSES}));
  cards.push_back(std::move(Card{VALUE_9, POINT_0, ESuit::CROSSES}));
  cards.push_back(std::move(Card{VALUE_J, POINT_J, ESuit::CROSSES}));
  cards.push_back(std::move(Card{VALUE_Q, POINT_Q, ESuit::CROSSES})); //
  cards.push_back(std::move(Card{VALUE_K, POINT_K, ESuit::CROSSES}));
  cards.push_back(std::move(Card{VALUE_T, POINT_T, ESuit::CROSSES}));
  cards.push_back(std::move(Card{VALUE_A, POINT_A, ESuit::CROSSES}));
}

void Deck::Shuffle(size_t seed) {
  std::random_device rd;
  std::mt19937_64 g(rd());
  g.seed(seed);
  std::shuffle(cards.begin(), cards.end(), g);
}

const Card &Deck::ShowCard(size_t pos) const { return cards[pos]; }

std::optional<Card> Deck::GiveOne() {
  if (static_cast<unsigned int>(!cards.empty()) != 0U) {
    Card temp = std::move(cards.back());
    cards.pop_back();
    return temp;
  }
  return {};
}

size_t Deck::Size() const { return cards.size(); }
