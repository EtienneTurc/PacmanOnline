#include <iostream>
#include "entity.h"
#include "game.h"
#include "parameters.h"

int main(int argc, char const *argv[])
{

    Game game;
    std::cout << "score : " << game.getScore() << "\n";
    game.updateScore(150);
    std::cout << "score : " << game.getScore() << "\n";
    std::cout << "status : " << game.getGhostsStatus() << "\n";
    game.updateGhostsStatus(FLEE);
    std::cout << "status : " << game.getGhostsStatus() << "\n";
    Grid grid;
    grid.displayGrid();

    Entity entity(&grid , 4, 5, LEFT, 1);
    std::cout << "Xposition " << int(entity.getXPosition()) << '\n';
    std::cout << "Yposition " << int(entity.getYPosition()) << '\n';
    std::cout << "Direction " << entity.getDirection() << '\n';
    std::cout << "Speed " << int(entity.getSpeed()) << '\n';
    std::cout << "New Direction " << entity.getDirection() << '\n';

    return 0;
}
