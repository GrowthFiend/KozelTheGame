#pragma once

#include <iostream>
#include <string>

#include "deck.h"
#include "player.h"

class IUserInterface {
  public:
  IUserInterface()                             = default;
  virtual void RenderTable(const Players& players, const Stake& stake, const Deck& deck,
      int score_t1, int score_t2) const        = 0;
  virtual void RenderFaceDown() const          = 0;
  virtual void RenderSpace(size_t count) const = 0;
  virtual void RenderWinner(int team) const    = 0;
  virtual std::string AskUserName() const      = 0;
  virtual void TrumpIs(Card& card) const       = 0;
  virtual void NeverBeliveInAce() const        = 0;
  virtual ~IUserInterface() {};
};
