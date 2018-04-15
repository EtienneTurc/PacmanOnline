#include <iostream>
#include "entity.h"
#include "game.h"

int main(int argc, char const *argv[])
{
    Entity entity(4, 5, 'L', 1, 3);
    std::cout << "Xposition " << int(entity.getXPosition()) << '\n';
    std::cout << "Yposition " << int(entity.getYPosition()) << '\n';
    std::cout << "Direction " << entity.getDirection() << '\n';
    std::cout << "Speed " << int(entity.getSpeed()) << '\n';
    std::cout << "Subsection " << int(entity.getSubsection()) << '\n';
    entity.updateDirection('R');
    std::cout << "New Direction " << entity.getDirection() << '\n';

    Game game;
    std::cout << "score : " << game.getScore() << "\n";
    game.updateScore(150);
    std::cout << "score : " << game.getScore() << "\n";
    std::cout << "status : " << game.getStatus() << "\n";
    game.updateStatus("New");
    std::cout << "status : " << game.getStatus() << "\n";
    game.displayGrid();

    return 0;
}
