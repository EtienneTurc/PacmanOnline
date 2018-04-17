#include "pacman.h"

Pacman::Pacman(Grid* grid, int x_position, int y_position, int direction, float speed) 
    : Entity(grid, x_position, y_position, direction, speed) {}
