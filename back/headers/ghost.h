#include <cstdint>

#ifndef GHOST_H
#define GHOST_H

class Ghost
{
public:

    int getState();
    unsigned int getTimeInJail();

    void updateSpeed(float new_speed);
    void updateTimeInJail();
    void updateState(int new_state);

    Ghost(uint8_t x_position, uint8_t y_position, char direction, float speed, uint8_t subsection);
    ~Ghost(){};
private:
    int _state;
    unsigned int _time_in_jail;
};


#endif //GHOST_H
