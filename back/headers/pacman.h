#ifndef PACMAN_H
#define PACMAN_H

#include "entity.h"

class Pacman : public Entity
{
public:
  void eat();

  Pacman(Grid *grid, int x_position, int y_position, int direction, float speed);
  ~Pacman() {}

private:
};

#endif
