#ifndef PACMAN_H
#define PACMAN_H

#include "entity.h"

class Pacman : public Entity 
{
public:
  Pacman(uint8_t x_position, uint8_t y_position, char direction, uint8_t speed, uint8_t subsection);
  ~Pacman() {}
  void eat(uint8_t **grid);
  void playerDirection(char direction);

private:
};

#endif 
