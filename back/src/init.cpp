#include "game.h"
#include "parameters.h"

void Game::init()
{
    //Grid already initialized

    //Initialisation pacman
    Pacman pacman(&_grid, 1, 4, DOWN, 1);
    _pacmans.push_back(pacman);

    //Initialisation ghost
    Ghost gasper(&_grid, 6,4,RIGHT,1, 0);
    _ghosts.push_back(gasper);

    _grid.displayGrid();
}