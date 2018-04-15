#ifndef ENTITY_H
#define ENTITY_H

#include <iostream>

class Entity
{
  public:
    Entity(uint8_t x_position, uint8_t y_position, char direction, uint8_t speed, uint8_t subsection);
    ~Entity() {}
    uint8_t getXPosition();
    uint8_t getYPosition();
    char getDirection();
    uint8_t getSpeed();
    uint8_t getSubsection();
    void move(uint8_t** grid);
    void updateDirection(char direction);

  protected:
    uint8_t _x_position;
    uint8_t _y_position;
    char _direction; //'U', 'D', 'L', 'R'
    uint8_t _speed;
    uint8_t _subsection;
};

#endif
