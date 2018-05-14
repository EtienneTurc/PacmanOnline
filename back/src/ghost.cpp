#include "ghost.h"

Ghost::Ghost(Grid* grid, int x_position, int y_position, int direction, float speed, int score, unsigned int time_in_jail)
: Entity(grid, x_position, y_position, direction, speed, score) {
	_time_in_jail = 0;
}

unsigned int Ghost::getTimeInJail() {
	return _time_in_jail;
}

void Ghost::updateSpeed(float new_speed) {
	_speed = new_speed;
}

void Ghost::updateTimeInJail() {
	//TODO
}
