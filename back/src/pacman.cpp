#include "pacman.h"

// Constructor
Pacman::Pacman(Grid *grid, int x_position, int y_position, int direction, float speed)
: Entity(grid, x_position, y_position, direction, speed, 0) {}

// A simple function that eat the balls and update the score of the pacman
int Pacman::eat() {
	uint8_t value = _grid->getCell(_x_position, _y_position);
	switch (value) {
		case SMALL_BALL: {
			_score = _score + SCORE_SMALL_BALL;
			_grid->setCell(_x_position, _y_position, TRACK);
			return SMALL_BALL;
			break;
		}
		case BIG_BALL: {
			_score = _score + SCORE_BIG_BALL;
			_grid->setCell(_x_position, _y_position, TRACK);
			return BIG_BALL;
			break;
		}
		case FRUIT: {
			_score = _score + SCORE_FRUIT;
			_grid->setCell(_x_position, _y_position, TRACK);
			return FRUIT;
			break;
		}
		default: {
			return TRACK;
			break;
		}
	}
}
