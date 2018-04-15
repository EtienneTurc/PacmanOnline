#include "game.h"

int main(int argc, char const *argv[])
{
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
