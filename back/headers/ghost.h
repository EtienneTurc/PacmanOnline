#include <cstdint>

#ifndef GHOST_H
#define GHOST_H

#include "entity.h"

class Ghost : public Entity {
public:
	unsigned int getTimeInJail();
	int getIaIndex();

	void updateSpeed(float new_speed);
	bool inJail();

	Ghost(Grid* grid, int x_position, int y_position, int direction, float speed, int score, unsigned int time_in_jail, int ia_index);
	~Ghost(){};
private:
	unsigned int _time_in_jail;
	int _ia_index;
};


#endif
