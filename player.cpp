#include "player.h"

void Player::TakeOneCard() {
  auto x = Deck::GetInstance().GiveOne();
  if (x.has_value()) hand.insert(std::move(x.value()));
}

bool Player::HasGenerals() const {
  int i = 0;
  for (const auto& card : hand) {
    if (card->value() >= 8) ++i;
  }
  return i == 4;
}

bool Player::HasSnotty() const {
  int i = 0;
  for (const auto& card : hand) {
    if (card->value() == 0 || card->value() == 18) ++i;
  }
  return i == 4;
}

bool Player::HasFlushOr41() const {
  int isFlush   = static_cast<int>((*hand.begin())->suit());
  int pointsSum = 0;
  bool hasShama = false;
  for (const auto& card : hand) {
    isFlush |= static_cast<int>(card->suit());
    pointsSum += card->points();
    if (card->suit() == ESuit::SHAMA) hasShama = true;
  }
  if (isFlush || pointsSum > 40 || (pointsSum > 29 && hasShama)) return true;
  else
    return false;
}

const std::set<std::unique_ptr<Card>>& Player::getHand() const { return hand; }
