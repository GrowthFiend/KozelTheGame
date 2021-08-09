#include <iostream>

#include "deck.h"
#include "game.h"

int main() {
  Deck::GetInstance().Shuffle(2);
  Deck::GetInstance().PrintCards(std::cout);
  Game game(EGameModes::PlayerX1, std::cin, std::cout);

  return 0;
}
