#include "game.h"
#include <thread>

// Constructor
Game::Game() {
	_time_to_flee = 0;
	std::vector<Pacman> _pacmans;
	std::vector<Ghost> _ghosts;
	Grid* _grid; //Grid constructor fills the grid
}

void Game::updateGhostsStatus(int new_time_to_flee) {
	_time_to_flee = new_time_to_flee;
}

std::vector<Pacman>* Game::getPacmans() {
	return &_pacmans;
}

std::vector<Ghost>* Game::getGhosts() {
	return &_ghosts;
}

Grid* Game::getGrid() {
	return _grid;
}

int Game::getTimeToFlee() {
	return _time_to_flee;
}

void Game::addGhost(Ghost new_ghost) {
	_ghosts.push_back(new_ghost);
}

void Game::addPacman(Pacman new_pacman) {
	_pacmans.push_back(new_pacman);
}

// Function that display the grid with the pacmans and ghosts (not used anymore)
void Game::displayEntities() {
	std::vector<uint8_t> pacmans_cells;
	for(unsigned int p = 0; p < _pacmans.size(); p++) {
		pacmans_cells.push_back(_grid->getCell(_pacmans[p].getXPosition(), _pacmans[p].getYPosition()));
		_grid->setCell(_pacmans[p].getXPosition(), _pacmans[p].getYPosition(), 9);
	}

	std::vector<uint8_t> ghosts_cells;
	for(unsigned int g = 0; g < _ghosts.size(); g++) {
		ghosts_cells.push_back(_grid->getCell(_ghosts[g].getXPosition(), _ghosts[g].getYPosition()));
		_grid->setCell(_ghosts[g].getXPosition(), _ghosts[g].getYPosition(), 8);
	}

	_grid->displayGrid();

	for (unsigned int p = 0; p < _pacmans.size(); p++) {
		uint8_t cell_value = pacmans_cells[p];
		if (cell_value != 9) {
			_grid->setCell(_pacmans[p].getXPosition(), _pacmans[p].getYPosition(), 1);
		}
	}

	for (unsigned int g = 0; g < _ghosts.size(); g++) {
		uint8_t cell_value = ghosts_cells[g];
		if (cell_value != 8) {
			_grid->setCell(_ghosts[g].getXPosition(), _ghosts[g].getYPosition(), ghosts_cells[g]);
		}
	}
}

// Function that initializes a game
void Game::init() {
	//Grid already initialized
	Grid *grid = new Grid();
	_grid = grid;

	//Initialisation pacman
	Pacman pacman(_grid, 18, 29, LEFT,  SPEED);
	addPacman(pacman);

	//Initialisation ghosts
	Ghost gasper(_grid, X_CENTER,Y_CENTER,DOWN,SPEED, GHOST_SCORE, 0, 0);
	addGhost(gasper);

	Ghost blanky(_grid, X_CENTER,Y_CENTER + 3 ,RIGHT, SPEED, GHOST_SCORE, 40,1);
	addGhost(blanky);

	Ghost inky(_grid, X_CENTER + 1 ,Y_CENTER + 3 ,RIGHT, SPEED, GHOST_SCORE, 80,2);
	addGhost(inky);

	Ghost pinky(_grid, X_CENTER -1  ,Y_CENTER + 3 ,RIGHT, SPEED, GHOST_SCORE, 120,3);
	addGhost(pinky);
	// displayEntities();
}

// Function that runs to game (called at each tick of the server)
void Game::run() {
	if (_time_to_flee) {
		_time_to_flee--;
	}

	// Moving the pacmans and eat the big ball
	for (unsigned int p = 0; p < _pacmans.size(); p++) {
		_pacmans[p].move(1);
		if (_pacmans[p].eat() == BIG_BALL) {
			updateGhostsStatus(TIME_TO_FLEE);
		}
	}

	// Defining the different possible ias
	std::vector<int (*)(Pacman, Ghost)> ia;
	ia.push_back(lowestDirection);
	ia.push_back(lowestDirectionToIntersection);
	ia.push_back(lowestDirectionUntilRandom);

	// Moving the ghosts
	for (unsigned int g = 0; g < _ghosts.size(); g++) {
		bool in_jail = _ghosts[g].inJail();
		if (!in_jail) {
			if (_time_to_flee || _ghosts[g].getIaIndex() == 3 ) {
				int direction = randomDirection(_ghosts[g]);
				_ghosts[g].pushInput(direction);
				_ghosts[g].move(1);
			} else {
				int direction = ia[_ghosts[g].getIaIndex()](_pacmans[0], _ghosts[g]);
				_ghosts[g].pushInput(direction);
				_ghosts[g].move(1);
			}
		}
	}

	// Eat the ghosts if it is allowed
	eatGhostsIfAllowed();
	// displayEntities();
}

// Function that returns true if the game is over
bool Game::gameOver() {
	//Return True if the game is over
	unsigned int count = 0;
	for (unsigned int p = 0; p < _pacmans.size(); p++) {
		for (unsigned int g = 0; g < _ghosts.size(); g++) {
			if (_ghosts[g].entityCollision(_pacmans[p]) && !_time_to_flee) {
				count++;
			}
		}
	}
	if (count == _pacmans.size()) {
		return true;
	}
	return false;
}

// Function that eats the ghosts if it's allowed and possible
void Game::eatGhostsIfAllowed() {
	if (_time_to_flee) {
		for (unsigned int p = 0; p < _pacmans.size(); p++) {
			for (unsigned int g = 0; g < _ghosts.size(); g++) {
				if (_ghosts[g].entityCollision(_pacmans[p])) {
					_ghosts[g].setXPosition(X_CENTER);
					_ghosts[g].setYPosition(Y_CENTER);
					_ghosts[g].updateDirection(RIGHT);
					_ghosts[g].setFraction(0.5);
					_pacmans[p].addScore(SCORE_EAT_GHOST);
				}
			}
		}
	}
}
