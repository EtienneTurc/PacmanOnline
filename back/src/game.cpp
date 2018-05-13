#include "game.h"

Game::Game() {
	_ghosts_status = ATTACK;
	std::vector<Pacman> _pacmans;
	std::vector<Ghost> _ghosts;
	Grid* _grid; //Grid constructor fills the grid
}

int Game::getGhostsStatus() {
	return _ghosts_status;
}

void Game::updateGhostsStatus(int new_ghosts_status) {
	_ghosts_status = new_ghosts_status;
}

std::vector<Pacman> Game::getPacmans() {
	return _pacmans;
}

std::vector<Ghost> Game::getGhosts() {
	return _ghosts;
}

void Game::addGhost(Ghost new_ghost) {
	_ghosts.push_back(new_ghost);
}

void Game::addPacman(Pacman new_pacman) {
	_pacmans.push_back(new_pacman);
}

void Game::displayEntities() {
	for(int p = 0; p < _pacmans.size(); p++) {
		_grid->setCell(_pacmans[p].getXPosition(), _pacmans[p].getYPosition(), 9);
	}

	std::vector<int> ghosts_cells;
	for(int g = 0; g < _ghosts.size(); g++) {
		ghosts_cells.push_back(_grid->getCell(_ghosts[g].getXPosition(), _ghosts[g].getYPosition()));
		_grid->setCell(_ghosts[g].getXPosition(), _ghosts[g].getYPosition(), 8);
	}

	_grid->displayGrid();

	for (int p = 0; p < _pacmans.size(); p++) {
		_grid->setCell(_pacmans[p].getXPosition(), _pacmans[p].getYPosition(), 1);
	}

	for (int g = 0; g < _ghosts.size(); g++) {
		_grid->setCell(_ghosts[g].getXPosition(), _ghosts[g].getYPosition(), ghosts_cells[g]);
	}
}

void Game::init() {
	//Grid already initialized
	Grid *grid = new Grid();
	_grid = grid;

	//Initialisation pacman
	Pacman pacman(_grid, 18, 29, LEFT, 10);
	_pacmans.push_back(pacman);

	//Initialisation ghost
	Ghost gasper(_grid, 6,10,UP,10, GHOST_SCORE, 0);
	_ghosts.push_back(gasper);

	Ghost blanky(_grid, 4,4,DOWN,10, GHOST_SCORE, 0);
	_ghosts.push_back(blanky);

	displayEntities();
}

void Game::run() {
	for(int i = 0; i < 20; i++) {

		for(int p = 0; p < _pacmans.size(); p++) {
			_pacmans[p].move(1);
		}

		for (int p = 0; p < _ghosts.size(); p++) {
			int direction = lowestDirection(_pacmans[0], _ghosts[p]);
			_ghosts[p].pushInput(direction);
			_ghosts[p].move(1);
		}

		displayEntities();
	}
}
