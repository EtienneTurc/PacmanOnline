#include "entity.h"

Entity::Entity(uint8_t **grid, uint8_t x_position, uint8_t y_position, char direction, uint8_t speed, uint8_t subsection)
{
    _grid = grid;
    _x_position = x_position;
    _y_position = y_position;
    _direction = direction;
    _speed = speed;
    _subsection = subsection;
}

uint8_t Entity::getXPosition()
{
    return _x_position;
}

uint8_t Entity::getYPosition()
{
    return _y_position;
}

char Entity::getDirection()
{
    return _direction;
}

uint8_t Entity::getSpeed()
{
    return _speed;
}

uint8_t Entity::getSubsection()
{
    return _subsection;
}

void Entity::move()
{
    // Wihtout subsection
    switch (_direction)
    {
    case 'R':
        if (_grid[_x_position][(_y_position + 1) % 28] != 0)
        {
            _y_position++;
        }
        break;
    case 'L':
        if (_grid[_x_position][(_y_position - 1) % 28] != 0)
        {
            _y_position--;
        }
        break;
    case 'U':
        if (_grid[(_x_position - 1) % 36][_y_position] != 0)
        {
            _x_position--;
        }
        break;
    case 'D':
        if (_grid[(_x_position + 1) % 36][_y_position] != 0)
        {
            _x_position++;
        }
        break;
    default:
        break;
    }
}

void Entity::updateDirection(char direction)
{
    _direction = direction;
}
