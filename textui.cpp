#include "textui.h"

#include <unistd.h>

#include "worku32srting.h"

const std::unordered_map<int, std::string> TextUI::SuitToColor {
    {static_cast<int>(ESuit::HEARTS), "\x1b[31;47m"},
    {static_cast<int>(ESuit::DIAMONDS), "\x1b[31;1;47m"},
    {static_cast<int>(ESuit::CROSSES), "\x1b[30;1;47m"},
    {static_cast<int>(ESuit::SPADES), "\x1b[30;47m"},
    {static_cast<int>(ESuit::ANY_SUIT), "\x1b[30;47m"},
};

void TextUI::RenderTable(const Players& players, const Stake& stake, const Deck& deck, int score_t1,
    int score_t2) const {
  //  usleep(200'000);
  system("clear");

  //str1
  RenderSpace(2);
  for (size_t i = 4; i != 0; --i) {
    if (players[2]->getHand().size() < i) RenderSpace(1);
    else
      RenderFaceDown();
  }
  RenderSpace(2);
  output << score_t1 << ':' << score_t2;
  output << std::endl;

  //str2
  RenderSpace(8);
  output << std::endl;

  //str3
  if (players[1]->getHand().size() < 1) RenderSpace(1);
  else
    RenderFaceDown();
  RenderSpace(1);
  RenderFaceDown();
  output << deck.Size() << ' ';
  if (deck.Size() < 10) output << ' ';
  RenderSpace(3);
  if (players[3]->getHand().size() < 4) RenderSpace(1);
  else
    RenderFaceDown();
  output << std::endl;

  //str4
  if (players[1]->getHand().size() < 2) RenderSpace(1);
  else
    RenderFaceDown();
  RenderSpace(1);
  for (size_t i = 1; i <= 4; ++i) {
    if (stake[0].second.size() < i) RenderSpace(1);
    else
      RenderFaceDown();
  }
  RenderSpace(1);
  if (players[3]->getHand().size() < 3) RenderSpace(1);
  else
    RenderFaceDown();
  output << std::endl;

  //str5
  if (players[1]->getHand().size() < 3) RenderSpace(1);
  else
    RenderFaceDown();
  RenderSpace(1);
  for (size_t i = 1; i <= 4; ++i) {
    if (stake[1].second.size() < i) RenderSpace(1);
    else
      RenderFaceDown();
  }
  RenderSpace(1);
  if (players[3]->getHand().size() < 2) RenderSpace(1);
  else
    RenderFaceDown();
  output << std::endl;

  //str6
  if (players[1]->getHand().size() < 4) RenderSpace(1);
  else
    RenderFaceDown();
  RenderSpace(1);
  for (size_t i = 1; i <= 4; ++i) {
    if (stake[2].second.size() < i) RenderSpace(1);
    else
      RenderFaceDown();
  }
  RenderSpace(1);
  if (players[3]->getHand().size() < 1) RenderSpace(1);
  else
    RenderFaceDown();
  output << std::endl;

  //str7
  RenderSpace(2);

  for (size_t i = 1; i <= 4; ++i) {
    if (stake[3].second.size() < i) RenderSpace(1);
    else
      RenderFaceDown();
  }
  RenderSpace(2);
  output << std::endl;

  //str8
  RenderSpace(2);
  size_t i = 4;
  for (const auto& card : players[0]->getHand()) {
    output << *card;
    --i;
  }
  while (i--) { RenderSpace(1); }
  output << std::endl;
}

void TextUI::RenderFaceDown() const {
  output << "\x1b[35;47m";
  output << U"\x1F0A0" << ' ';
  output << "\x1b[0m";
  output << ' ';
}

void TextUI::RenderSpace(size_t count) const {
  while (count--) output << "   ";
}

void TextUI::RenderWinner(int team) const { output << "Team" << team << " win!" << std::endl; }

std::string TextUI::AskUserName() const {
  std::string username;
  output << "Please, enter youre name: ";
  input >> username;
  return username;
}

std::u32string GenCardName(const Card& card) {
  char32_t suit;
  if (card.suit() == ESuit::HEARTS) suit = 0xB << 4;
  else if (card.suit() == ESuit::DIAMONDS)
    suit = 0xC << 4;
  else if (card.suit() == ESuit::CROSSES)
    suit = 0xD << 4;
  else
    suit = 0xA << 4;
  char32_t nominal;
  if (card.value() % 18 == 0) nominal = 0x6;
  else if (card.value() == 1)
    nominal = 0x7;
  else if (card.value() == 2)
    nominal = 0x8;
  else if (card.value() == 3)
    nominal = 0x9;
  else if (card.value() == 4)
    nominal = 0xB;
  else if (card.value() == 5)
    nominal = 0xD;
  else if (card.value() == 6)
    nominal = 0xE;
  else if (card.value() == 7)
    nominal = 0xA;
  else
    nominal = 0x1;
  char32_t result = 0x1F000 + suit + nominal;
  return {result};
}

void TextUI::TrumpIs(Card& card) const { output << "Trump is: " << card << std::endl; }

void TextUI::NeverBeliveInAce() const { output << "Never belive in Ace!" << std::endl; }

std::ostream& operator<<(std::ostream& os, const Card& card) {
  os << TextUI::SuitToColor.at(static_cast<int>(card.suit()));
  os << GenCardName(card) << ' ';
  os << "\x1b[0m";
  os << ' ';
  return os;
}
