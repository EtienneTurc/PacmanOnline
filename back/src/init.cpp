#include "game.h"

void Game::init() {
	//Grid already initialized
	Grid *grid = new Grid();
	_grid = grid;

	//Initialisation pacman
	Pacman pacman(_grid, 4, 4, LEFT, 10);
	_pacmans.push_back(pacman);

	//Initialisation ghost
	Ghost gasper(_grid, 6,10,UP,10, GHOST_SCORE, 0);
	_ghosts.push_back(gasper);

	Ghost blanky(_grid, 6,11,DOWN,10, GHOST_SCORE, 0);
	_ghosts.push_back(blanky);

	displayEntities();
}
