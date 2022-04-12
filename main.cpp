#include <iostream>

#include "game.h"
#include "textui.h"

int main() {
  Game game(EGameModes::PlayerX1,
            std::make_unique<TextUI>(std::cin, std::cout));
  game.Start();
  return 0;
}
