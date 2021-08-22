#include "textrender.h"

#include <unistd.h>

void TextRender::Table() const {
  usleep(200'000);
  system("clear");

  //str1
  Space(2);
  for (size_t i = 4; i != 0; --i) {
    if (players[2]->getHand().size() < i) Space(1);
    else
      FaceDown();
  }
  Space(2);
  output << score_t1 << ':' << score_t2;
  output << std::endl;

  //str2
  Space(8);
  output << std::endl;

  //str3
  if (players[1]->getHand().size() < 1) Space(1);
  else
    FaceDown();
  Space(1);
  FaceDown();
  output << Deck::GetInstance().Size() << ' ';
  if (Deck::GetInstance().Size() < 10) output << ' ';
  Space(3);
  if (players[3]->getHand().size() < 4) Space(1);
  else
    FaceDown();
  output << std::endl;

  //str4
  if (players[1]->getHand().size() < 2) Space(1);
  else
    FaceDown();
  Space(1);
  for (size_t i = 1; i <= 4; ++i) {
    if (table[0].second.size() < i) Space(1);
    else
      FaceDown();
  }
  Space(1);
  if (players[3]->getHand().size() < 3) Space(1);
  else
    FaceDown();
  output << std::endl;

  //str5
  if (players[1]->getHand().size() < 3) Space(1);
  else
    FaceDown();
  Space(1);
  for (size_t i = 1; i <= 4; ++i) {
    if (table[1].second.size() < i) Space(1);
    else
      FaceDown();
  }
  Space(1);
  if (players[3]->getHand().size() < 2) Space(1);
  else
    FaceDown();
  output << std::endl;

  //str6
  if (players[1]->getHand().size() < 4) Space(1);
  else
    FaceDown();
  Space(1);
  for (size_t i = 1; i <= 4; ++i) {
    if (table[2].second.size() < i) Space(1);
    else
      FaceDown();
  }
  Space(1);
  if (players[3]->getHand().size() < 1) Space(1);
  else
    FaceDown();
  output << std::endl;

  //str7
  Space(2);

  for (size_t i = 1; i <= 4; ++i) {
    if (table[3].second.size() < i) Space(1);
    else
      FaceDown();
  }
  Space(2);
  output << std::endl;

  //str8
  Space(2);
  size_t i = 4;
  for (const auto& card : players[0]->getHand()) {
    output << *card;
    --i;
  }
  while (i--) { Space(1); }
  output << std::endl;
}

void TextRender::FaceDown() const {
  output << "\x1b[35;47m";
  output << U"\x1F0A0" << ' ';
  output << "\x1b[0m";
  output << ' ';
}

void TextRender::Space(size_t count) const {
  while (count--) output << "   ";
}

std::string TextRender::AskUserName() const {
  std::string username;
  output << "Please, enter youre name: ";
  input >> username;
  return username;
}
