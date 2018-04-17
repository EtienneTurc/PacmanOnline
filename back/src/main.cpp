#include <iostream>
#include "entity.h"
#include "game.h"
#include "parameters.h"

int main(int argc, char const *argv[])
{

    Game game;
    game.init();
    
    std::vector<Pacman> pacmans = game.getPacmans();
    for (int i = 0; i < pacmans.size(); i++)
    {
        std::cout << pacmans[i].getXPosition();
    }

    return 0;
}
