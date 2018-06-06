#include "entity.h"

Entity::Entity(Grid *grid, int x_position, int y_position, int direction, float speed, int score) {
	_grid = grid;
	_x_position = x_position;
	_y_position = y_position;
	_direction = direction;
	_speed = speed;
	_fraction = 1 / 2;
	_event = 0;
	_score = score;
	_input_time = 0;
}

int Entity::getXPosition() {
	return _x_position;
}

int Entity::getYPosition() {
	return _y_position;
}

int Entity::getDirection() {
	return _direction;
}

float Entity::getSpeed() {
	return _speed;
}

float Entity::getFraction() {
	return _fraction;
}

int Entity::getScore() {
	return _score;
}

Grid* Entity::getGrid() {
	return _grid;
}

void Entity::setXPosition(int x_position) {
	_x_position = x_position;
}

void Entity::setYPosition(int y_position) {
	_y_position = y_position;
}

void Entity::setInputTime(int input_time) {
	_input_time = input_time;
}

void Entity::addScore(int score_to_add) {
	_score += score_to_add;
}

bool Entity::entityCollision(Entity entity) {
	int x_pos = entity.getXPosition();
	int y_pos = entity.getYPosition();
	int dir = entity.getDirection();
	float fract = entity.getFraction();

	if ( (_x_position != x_pos) || (_y_position != y_pos)) {
		return 0;
	} else {
		if (dir%2 == _direction%2) {
			if (dir != _direction){
				return (abs(1-fract-_fraction) <= COLLISION_RANGE);
			} else {
				return (abs(fract-_fraction) <= COLLISION_RANGE);
			}
		} else {
			return (((0.5-fract)*(0.5-fract) + (0.5-_fraction)*(0.5-_fraction)) <= COLLISION_RANGE*COLLISION_RANGE);
		}
	}
}

int Entity::distanceTo(int x_position, int y_position) {
	return (abs(x_position - _x_position) +  abs(y_position - _y_position));
}

void Entity::pushInput(int direction) {
	_event = direction;
}

void Entity::updateDirection(int direction) {
	if (!_grid->checkWall(_x_position, _y_position, direction) && _direction != direction) {
		if (((direction + 1)%4 +1) == _direction) {
			_fraction = 1 - _fraction;
			_direction = direction;
		} else if ( abs(0.5-_fraction) < TURN_RANGE) {
			_fraction = 0.5;
			_direction = direction;
		}
	}
}

void Entity::updateFraction() {
	// _fraction can not overtake 0.5 if there is a wall
	while (_fraction >= 1) {
		_fraction = _fraction - 1;
	}
	if (_grid->checkWall(_x_position, _y_position, _direction) && (_fraction >= 0.5)) {
		_fraction = 0.5;
	}
}

void Entity::move(float delta_time) {
	// Update the direction
	if (_event) {
		updateDirection(_event);
		if (!_input_time) {
			_event = 0;
		} else {
			_input_time--;
		}
	}

	// Check if there is a wall in front
	if (!_grid->checkWall(_x_position, _y_position, _direction) || _fraction < 0.5) {
		// Update the current position
		_fraction = _fraction + delta_time * _speed;
		switch (_direction) {
			case LEFT: {
				if (_fraction >= 0.5 && _x_position == 0) {
					_x_position = 27;
					_fraction = 0;
				} else if (_fraction >= 1) {
					_x_position = (_x_position - 1) % 28;
				}
				updateFraction();
				break;
			}
			case RIGHT: {
				if (_fraction >= 1) {
					_x_position = (_x_position + 1) % 28;
				}
				updateFraction();
				break;
			}
			case UP: {
				if (_fraction >= 1) {
					_y_position = (_y_position - 1) % 36;
				}
				updateFraction();
				break;
			}
			case DOWN: {
				if (_fraction >= 1) {
					_y_position = (_y_position + 1) % 36;
				}
				updateFraction();
				break;
			}
			default: {
				break;
			}
		}
	}
}

void Entity::virtualMove() {
	switch (_direction) {
		case LEFT: {
			if (_x_position == 0) {
				_x_position = 27;
			} else {
				_x_position = (_x_position - 1 + 28) % 28;
			}
			break;
		}
		case RIGHT: {
			_x_position = (_x_position + 1) % 28;
			break;
		}
		case UP: {
			_y_position = (_y_position - 1) % 36;
			break;
		}
		case DOWN: {
			_y_position = (_y_position + 1) % 36;
			break;
		}
		default: {
			break;
		}
	}
}
