#include "game.h"

void Game::init()
{
    //Grid already initialized

    //Initialisation pacman
    Pacman pacman(_grid, 4, 1, DOWN, 1);
    _pacmans.push_back(pacman);

    //Initialisation ghost
    Ghost gasper(_grid, 4,6,RIGHT,1, GHOST_SCORE, 0);
    _ghosts.push_back(gasper);

    Grid *grid = new Grid();
    _grid = grid;
    displayEntities();
}