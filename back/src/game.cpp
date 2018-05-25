#include "game.h"

Game::Game() {
	_time_to_flee = 0;
	std::vector<Pacman> _pacmans;
	std::vector<Ghost> _ghosts;
	Grid* _grid; //Grid constructor fills the grid
}

int Game::getGhostsStatus() {
	return _time_to_flee;
}

void Game::updateGhostsStatus(int new_time_to_flee) {
	_time_to_flee = new_time_to_flee;
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
	std::vector<uint8_t> pacmans_cells;
	for(int p = 0; p < _pacmans.size(); p++) {
		pacmans_cells.push_back(_grid->getCell(_pacmans[p].getXPosition(), _pacmans[p].getYPosition()));
		_grid->setCell(_pacmans[p].getXPosition(), _pacmans[p].getYPosition(), 9);
	}

	std::vector<uint8_t> ghosts_cells;
	for(int g = 0; g < _ghosts.size(); g++) {
		ghosts_cells.push_back(_grid->getCell(_ghosts[g].getXPosition(), _ghosts[g].getYPosition()));
		_grid->setCell(_ghosts[g].getXPosition(), _ghosts[g].getYPosition(), 8);
	}

	_grid->displayGrid();

	for (int p = 0; p < _pacmans.size(); p++) {
		uint8_t cell_value = pacmans_cells[p];
		if (cell_value != 9) {
			_grid->setCell(_pacmans[p].getXPosition(), _pacmans[p].getYPosition(), 1);
		}
	}

	for (int g = 0; g < _ghosts.size(); g++) {
		uint8_t cell_value = ghosts_cells[g];
		if (cell_value != 8) {
			_grid->setCell(_ghosts[g].getXPosition(), _ghosts[g].getYPosition(), ghosts_cells[g]);
		}
	}
}

void Game::init() {
	//Grid already initialized
	Grid *grid = new Grid();
	_grid = grid;

	//Initialisation pacman
	Pacman pacman(_grid, 18, 29, LEFT, 10);
	addPacman(pacman);

	//Initialisation ghost
	Ghost gasper(_grid, 16,26,DOWN,10, GHOST_SCORE, 0);
	addGhost(gasper);

	Ghost blanky(_grid, X_CENTER,Y_CENTER + 2 ,DOWN,10, GHOST_SCORE, 10);
	addGhost(blanky);
	std::cout << "Time in jail : " << _ghosts[1].getTimeInJail() << '\n';

	displayEntities();
}

void Game::run() {
	bool game_over = false;
	while (!game_over) {

		if (_time_to_flee) {
			_time_to_flee--;
		}

		for (int p = 0; p < _pacmans.size(); p++) {
			int direction = randomDirection(_pacmans[p]);
			_pacmans[p].pushInput(direction);
			_pacmans[p].move(1);
			if (_pacmans[p].eat() == BIG_BALL) {
				updateGhostsStatus(TIME_TO_FLEE);
			}
			std::cout << "Score :" << _pacmans[p].getScore() << "\n";
		}

		eatGhostsIfAllowed();

		game_over = gameOver();
		if (game_over) {
			break;
		}
		std::vector<int (*)(Pacman, Ghost)> ia;
		ia.push_back(lowestDirection);
		ia.push_back(lowestDirectionToIntersection);
		ia.push_back(lowestDirectionUntilRandom);

		for (int g = 0; g < _ghosts.size(); g++) {
			bool in_jail = _ghosts[g].inJail();
			std::cout << "In jail :" << in_jail << "\n";
			if (!in_jail) {
				if (_time_to_flee) {
					int direction = randomDirection(_ghosts[g]);
					_ghosts[g].pushInput(direction);
					_ghosts[g].move(1);
				} else {
					int direction = ia[1](_pacmans[0], _ghosts[g]);
					_ghosts[g].pushInput(direction);
					_ghosts[g].move(1);
				}
			}
		}

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

void Game::eatGhostsIfAllowed() {
	//Return True if the game is over
	if (_time_to_flee) {
		for (int p = 0; p < _pacmans.size(); p++) {
			for (int g = 0; g < _ghosts.size(); g++) {
				if (_ghosts[g].entityCollision(_pacmans[p])) {
					_ghosts[g].setXPosition(X_CENTER);
					_ghosts[g].setYPosition(Y_CENTER);
					_pacmans[p].addScore(SCORE_EAT_GHOST);
				}
			}
		}
	}
}
