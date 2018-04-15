#include "ghost.h"

Ghost::Ghost(uint8_t x_position, uint8_t y_position, char direction, uint8_t speed, uint8_t subsection) : Entity(x_position, y_position, direction, speed, subsection) {
    _state = 0;
    _time_in_jail = 0;
}

int Ghost::getState() {
    return _state;
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

void Ghost::updateState(int new_state) {
    _state = new_state;
}