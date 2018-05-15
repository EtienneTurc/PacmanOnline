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
	Ghost gasper(_grid, 6,10,DOWN,10, GHOST_SCORE, 0);
	_ghosts.push_back(gasper);

	Ghost blanky(_grid, 4,4,DOWN,10, GHOST_SCORE, 0);
	_ghosts.push_back(blanky);

	displayEntities();
}

void Game::run() {
	bool game_over = false;
	while (!game_over) {

		for (int p = 0; p < _pacmans.size(); p++) {
			int direction = randomDirection(_pacmans[p]);
			_pacmans[p].pushInput(direction);
			_pacmans[p].move(1);
		}

		game_over = gameOver();
		if (game_over) {
			break;
		}

		// for (int g = 0; g < _ghosts.size(); g++) {
			// int direction = lowestDirection(_pacmans[0], _ghosts[0]);
			// _ghosts[0].pushInput(direction);
			// _ghosts[0].move(1);
			int direction = lowestDirectionUntilRandom(_pacmans[0], _ghosts[0]);
			_ghosts[0].pushInput(direction);
			_ghosts[0].move(1);
			direction = lowestDirectionToIntersection(_pacmans[0], _ghosts[1]);
			_ghosts[1].pushInput(direction);
			_ghosts[1].move(1);
		// }

		displayEntities();

		if (!game_over) {
			game_over = gameOver();
		}
	}
}

bool Game::gameOver() {
	//Return True if the game is over
	int count = 0;
	for (int p = 0; p < _pacmans.size(); p++) {
		for (int g = 0; g < _ghosts.size(); g++) {
			if (_ghosts[g].entityCollision(_pacmans[p])) {
				count++;
			}
		}
	}
	if (count == _pacmans.size()) {
		return true;
	}
	return false;
}
