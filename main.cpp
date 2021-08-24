#include <iostream>

#include "game.h"
#include "textui.h"

int main() {
  //  Game game(EGameModes::PlayerX1, std::make_unique<TextUI>(std::cin, std::cout));
  //  game.Start();

  std::vector<Card> v = {{0, 0, ESuit::CROSSES}, {0, 0, ESuit::DIAMONDS}, {0, 0, ESuit::HEARTS},
      {2, 0, ESuit::DIAMONDS}, {1, 0, ESuit::DIAMONDS}};
  std::vector<Card> n;

  for (const auto& item : v) std::cout << item;
  std::cout << std::endl;

  for (const auto& item : n) std::cout << item;
  std::cout << std::endl;

  n.push_back(std::move(v[3]));
  v.erase(
      std::remove_if(v.begin(), v.end(), [&](auto c) { return c.suit() == ESuit::NONE; }), v.end());
  //    n = std::move(v);
  //  n.insert(n.begin(), std::move_iterator(++v.begin()), std::move_iterator(v.end()));

  for (const auto& item : v) std::cout << item;
  std::cout << std::endl;

  for (const auto& item : n) std::cout << item;
  std::cout << std::endl;

  return 0;
}
