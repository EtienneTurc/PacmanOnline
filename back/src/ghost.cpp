#include "ghost.h"

Ghost::Ghost(Grid* grid, int x_position, int y_position, int direction, float speed, int score, unsigned int time_in_jail)
: Entity(grid, x_position, y_position, direction, speed, score) {
	_time_in_jail = time_in_jail;
}

unsigned int Ghost::getTimeInJail() {
	return _time_in_jail;
}

void Ghost::updateSpeed(float new_speed) {
	_speed = new_speed;
}

void Ghost::updateTimeInJail() {
	if (_time_in_jail > 1) {
		_time_in_jail --;
	} else if (_time_in_jail == 1) {
		setXPosition(X_CENTER);
		setYPosition(Y_CENTER);
		_time_in_jail --;
	}
	std::cout << "Time in jail : " << _time_in_jail << '\n';
}
