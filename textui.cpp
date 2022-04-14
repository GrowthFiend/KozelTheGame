#include "textui.hpp"

#include <string>
#include <unistd.h>

#include "deck.hpp"
#include "game.hpp"
#include "worku32srting.hpp"

const std::unordered_map<int, std::string> TextUI::SuitToColor{
    {static_cast<int>(ESuit::NONE), "\x1b[0m"},
    {static_cast<int>(ESuit::HEARTS), "\x1b[31;47m"},
    {static_cast<int>(ESuit::DIAMONDS), "\x1b[31;1;47m"},
    {static_cast<int>(ESuit::CROSSES), "\x1b[30;1;47m"},
    {static_cast<int>(ESuit::SPADES), "\x1b[30;47m"},
    {static_cast<int>(ESuit::ANY_SUIT), "\x1b[30;47m"},
};

void TextUI::RenderTable(const Players &players, const Stake &stake,
                         const Deck &deck, int score_t1, int score_t2) const {
  usleep(STEP_TIME);
  system("clear");

  // str1
  RenderSpace(2);
  for (size_t i = 4; i != 0; --i) {
    if (players[2]->getHand().size() < i ||
        players[2]->getHand()[i - 1].suit() == ESuit::NONE) {
      RenderSpace(1);
    } else {
      RenderFaceDown();
    }
  }
  RenderSpace(2);
  output << score_t1 << ':' << score_t2;
  output << std::endl;

  // str2
  RenderSpace(8);
  output << std::endl;

  // str3
  if (players[1]->getHand().empty() ||
      players[1]->getHand()[0].suit() == ESuit::NONE) {
    RenderSpace(1);
  } else {
    RenderFaceDown();
  }
  RenderSpace(1);
  RenderFaceDown();
  output << deck.Size() << ' ';
  if (deck.Size() < 10) {
    output << ' ';
  }
  RenderSpace(3);
  if (players[3]->getHand().size() < 4 ||
      players[3]->getHand()[3].suit() == ESuit::NONE) {
    RenderSpace(1);
  } else {
    RenderFaceDown();
  }
  output << std::endl;

  // str4
  if (players[1]->getHand().size() < 2 ||
      players[1]->getHand()[1].suit() == ESuit::NONE) {
    RenderSpace(1);
  } else {
    RenderFaceDown();
  }
  RenderSpace(1);
  for (size_t i = 1; i <= 4; ++i) {
    if (stake[0].second.size() < i) {
      RenderSpace(1);
    } else if (!stake[0].first) {
      RenderFaceDown();
    } else {
      output << stake[0].second[i - 1];
    }
  }
  RenderSpace(1);
  if (players[3]->getHand().size() < 3 ||
      players[3]->getHand()[2].suit() == ESuit::NONE) {
    RenderSpace(1);
  } else {
    RenderFaceDown();
  }
  output << std::endl;

  // str5
  if (players[1]->getHand().size() < 3 ||
      players[1]->getHand()[2].suit() == ESuit::NONE) {
    RenderSpace(1);
  } else {
    RenderFaceDown();
  }
  RenderSpace(1);
  for (size_t i = 1; i <= 4; ++i) {
    if (stake[1].second.size() < i) {
      RenderSpace(1);
    } else if (!stake[1].first) {
      RenderFaceDown();
    } else {
      output << stake[1].second[i - 1];
    }
  }
  RenderSpace(1);
  if (players[3]->getHand().size() < 2 ||
      players[3]->getHand()[1].suit() == ESuit::NONE) {
    RenderSpace(1);
  } else {
    RenderFaceDown();
  }
  output << std::endl;

  // str6
  if (players[1]->getHand().size() < 4 ||
      players[1]->getHand()[3].suit() == ESuit::NONE) {
    RenderSpace(1);
  } else {
    RenderFaceDown();
  }
  RenderSpace(1);
  for (size_t i = 1; i <= 4; ++i) {
    if (stake[2].second.size() < i) {
      RenderSpace(1);
    } else if (!stake[2].first) {
      RenderFaceDown();
    } else {
      output << stake[2].second[i - 1];
    }
  }
  RenderSpace(1);
  if (players[3]->getHand().empty() ||
      players[3]->getHand()[0].suit() == ESuit::NONE) {
    RenderSpace(1);
  } else {
    RenderFaceDown();
  }
  output << std::endl;

  // str7
  RenderSpace(2);

  for (size_t i = 1; i <= 4; ++i) {
    if (stake[3].second.size() < i) {
      RenderSpace(1);
    } else if (!stake[3].first) {
      RenderFaceDown();
    } else {
      output << stake[3].second[i - 1];
    }
  }
  RenderSpace(2);
  output << std::endl;

  // str8
  RenderSpace(2);
  size_t i = 4;
  for (const auto &card : players[0]->getHand()) {
    output << card;
    --i;
  }
  while ((i--) != 0U) {
    RenderSpace(1);
  }
  output << std::endl;
}

void TextUI::RenderFaceDown() const {
  output << "\x1b[35;47m";
  output << U"\x1F0A0" << ' ';
  output << "\x1b[0m";
  output << ' ';
}

void TextUI::RenderSpace(size_t count) const {
  while ((count--) != 0U) {
    output << "   ";
  }
}

void TextUI::RenderWinner(int team) const {
  output << "Team" << team << " win!" << std::endl;
}

std::string TextUI::AskUserName() const {
  std::string username;
  output << "Please, enter youre name: ";
  input >> username;
  return username;
}

std::u32string GenCardName(const Card &card) {
  char32_t suit = 0;

  if (card.suit() == ESuit::HEARTS) {
    suit = UNICODE_HEARTS << 4;
  } else if (card.suit() == ESuit::DIAMONDS) {
    suit = UNICODE_DIAMONDS << 4;
  } else if (card.suit() == ESuit::CROSSES) {
    suit = UNICODE_CROSSES << 4;
  } else if (card.suit() == ESuit::SPADES) {
    suit = UNICODE_SPADES << 4;
  } else {
    return {UNICODE_DEFAULT};
  }

  char32_t nominal = 0;
  if (card.value() % VALUE_S == VALUE_6) {
    nominal = UNICODE_6;
  } else if (card.value() == VALUE_7) {
    nominal = UNICODE_7;
  } else if (card.value() == VALUE_8) {
    nominal = UNICODE_8;
  } else if (card.value() == VALUE_9) {
    nominal = UNICODE_9;
  } else if (card.value() == VALUE_J) {
    nominal = UNICODE_J;
  } else if (card.value() == VALUE_Q) {
    nominal = UNICODE_Q;
  } else if (card.value() == VALUE_K) {
    nominal = UNICODE_K;
  } else if (card.value() == VALUE_T) {
    nominal = UNICODE_T;
  } else // VALUE_A
  {
    nominal = UNICODE_A;
  }
  char32_t result = UTICODE_PREFIX + suit + nominal;
  return {result};
}

void TextUI::TrumpIs(const Card &card) const {
  output << "Trump is: " << card << std::endl;
}

void TextUI::NeverBeliveInAce() const {
  output << "Never belive in Ace!" << std::endl;
}

std::ostream &operator<<(std::ostream &os, const Card &card) {
  os << TextUI::SuitToColor.at(static_cast<int>(card.suit()));
  os << GenCardName(card) << ' ';
  os << "\x1b[0m";
  os << ' ';
  return os;
}
