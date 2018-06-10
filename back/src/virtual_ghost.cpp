#include "virtual_ghost.h"

// Constructor
Virtual_ghost::Virtual_ghost(int initial_direction, Grid* grid, int x_position, int y_position, int direction)
 	: Entity(grid, x_position, y_position, direction, 1, 0)
	{
	_initial_direction = initial_direction;
}

int Virtual_ghost::getInitialDirection() {
	return _initial_direction;
}
