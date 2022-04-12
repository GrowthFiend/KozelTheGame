#pragma once

#include <unordered_map>

#include "iuserinterface.h"

class TextUI : public IUserInterface {
public:
  TextUI(std::istream &is, std::ostream &os) : input(is), output(os){};
  ~TextUI(){};
  static const std::unordered_map<int, std::string> SuitToColor;
  // IRenderSystem interface
public:
  void RenderTable(const Players &players, const Stake &stake, const Deck &deck,
                   int score_t1, int score_t2) const override;
  void RenderFaceDown() const override;
  void RenderSpace(size_t count) const override;
  void RenderWinner(int team) const override;
  void TrumpIs(const Card &card) const override;
  void NeverBeliveInAce() const override;
  std::string AskUserName() const override;

private:
  std::istream &input;
  std::ostream &output;
};

std::u32string GenCardName(const Card &card);
std::ostream &operator<<(std::ostream &os, const Card &card);
