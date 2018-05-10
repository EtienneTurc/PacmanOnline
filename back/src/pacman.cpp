#include "pacman.h"

Pacman::Pacman(Grid *grid, int x_position, int y_position, int direction, float speed)
: Entity(grid, x_position, y_position, direction, speed, 0) {}

void Pacman::eat() {
	uint8_t value = _grid->getCell(_x_position, _y_position);
	switch (value) {
		case 2: {
			_score = _score + SCORE_SMALL_BALL;
			_grid->setCell(_x_position, _y_position, 1);
			break;
		}
		case 3: {
			_score = _score + SCORE_BIG_BALL;
			_grid->setCell(_x_position, _y_position, 1);
			break;
		}
		case 4: {
			_score = _score + SCORE_FRUIT;
			_grid->setCell(_x_position, _y_position, 1);
			break;
		}
		default: {
			break;
		}
	}
}
