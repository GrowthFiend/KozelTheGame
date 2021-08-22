#include <iostream>

#include "game.h"
#include "textrender.h"

int main() {
  TextRender tr(std::cin, std::cout);
  Game game(EGameModes::PlayerX1, tr);
  game.Start();

  return 0;
}
