#include <cstdint>

#ifndef GHOST_H
#define GHOST_H

#include "entity.h"

class Ghost : public Entity
{
public:
    unsigned int getTimeInJail();

    void updateSpeed(float new_speed);
    void updateTimeInJail();

    Ghost(Grid* grid, int x_position, int y_position, int direction, float speed, unsigned int time_in_jail);
    ~Ghost(){};
private:
    unsigned int _time_in_jail;
};


#endif 
