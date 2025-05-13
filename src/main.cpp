#include "Game.h"
#include <iostream>

int main()
{
    Game game = Game();
    game.run();
    std::cout << "Game Loop Ended." << std::endl;
}