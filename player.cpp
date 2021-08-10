#include "player.h"

void Player::TakeOneCard() {
  auto x = Deck::GetInstance().GiveOne();
  if (x.has_value()) hand.insert(std::move(x.value()));
}

const std::set<std::unique_ptr<Card>> &Player::getHand() const { return hand; }
