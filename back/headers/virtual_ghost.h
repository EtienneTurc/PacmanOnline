#ifndef VIRTUAL_GHOST
#define VIRTUAL_GHOST

#include "ghost.h"

class Virtual_ghost : public Entity {
	public:
		int getInitialDirection();

		Virtual_ghost(int initial_direction, Grid* grid, int x_position, int y_position, int direction);
		~Virtual_ghost(){};

	private:
		int _initial_direction;
};

#endif
