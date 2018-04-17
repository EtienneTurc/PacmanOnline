#include <iostream>
#include "entity.h"
#include "game.h"
#include "parameters.h"

int main(int argc, char const *argv[])
{

    Game game;
    game.init();

    game.run();

    std::cout << "Loop ended succesfully\n";

    return 0;
}
