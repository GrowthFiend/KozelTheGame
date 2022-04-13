#pragma once

#include <iostream>
#include <string>

#include "deck.hpp"
#include "player.hpp"

class IUserInterface {
public:
  IUserInterface() = default;
  IUserInterface(const IUserInterface &) = delete;
  auto operator=(IUserInterface &) -> IUserInterface & = delete;
  IUserInterface(const IUserInterface &&) = delete;
  auto operator=(IUserInterface &&) -> IUserInterface & = delete;
  virtual ~IUserInterface() = default;
  virtual void RenderTable(const Players &players, const Stake &stake,
                           const Deck &deck, int score_t1,
                           int score_t2) const = 0;
  virtual void RenderFaceDown() const = 0;
  virtual void RenderSpace(size_t count) const = 0;
  virtual void RenderWinner(int team) const = 0;
  [[nodiscard]] virtual auto AskUserName() const -> std::string = 0;
  virtual void TrumpIs(const Card &card) const = 0;
  virtual void NeverBeliveInAce() const = 0;
};
