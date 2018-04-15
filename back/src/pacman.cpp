#include "pacman.h"

Pacman::Pacman(uint8_t x_position, uint8_t y_position, char direction, uint8_t speed, uint8_t subsection) : Entity(x_position, y_position, direction, speed, subsection) {

}

void playerDirection(int direction) {
    
    
    _events.push(direction);
}