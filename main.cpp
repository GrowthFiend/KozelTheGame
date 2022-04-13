#include <iostream>

#include "game.hpp"
#include "textui.hpp"

auto main() -> int {
  Game game(EGameModes::PlayerX1,
            std::make_unique<TextUI>(std::cin, std::cout));
  game.Start();
  return 0;
}
