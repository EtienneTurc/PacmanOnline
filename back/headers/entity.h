#ifndef ENTITY_H
#define ENTITY_H

#include <queue>
#include <cstdint>
#include "grid.h"

class Entity
{
  public:

    int getXPosition();
    int getYPosition();
    int getDirection();
    float getSpeed();
    float getFraction();

    void move();
    void updateDirection(int direction);
    void pushInput(int direction);
  
    Entity(Grid* grid, int x_position, int y_position, int direction, float speed);
    ~Entity() {}

  protected:
    std::queue<uint8_t> _events;
    Grid* _grid;
    int _x_position;
    int _y_position;
    int _direction;
    float _speed;
    float _fraction;
};

#endif
