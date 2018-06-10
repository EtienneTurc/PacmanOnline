#include "ghost.h"

// Constructor
Ghost::Ghost(Grid* grid, int x_position, int y_position, int direction, float speed, int score, unsigned int time_in_jail, int ia_index)
: Entity(grid, x_position, y_position, direction, speed, score) {
	_time_in_jail = time_in_jail;
	_ia_index = ia_index;
}

unsigned int Ghost::getTimeInJail() {
	return _time_in_jail;
}

int Ghost::getIaIndex() {
	return _ia_index;
}

void Ghost::updateSpeed(float new_speed) {
	_speed = new_speed;
}

// Function that returns true if the ghost is in jail ( and free the ghost if he is going to go out)
bool Ghost::inJail() {
	if (_time_in_jail == 0) {
		return false;
	} else {
		if (_time_in_jail == 1) {
			setXPosition(X_CENTER);
			setYPosition(Y_CENTER);
		}
		_time_in_jail--;
		return true;
	}
}
