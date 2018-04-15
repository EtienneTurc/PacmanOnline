#include "entity.h"

Entity::Entity(Grid* grid, int x_position, int y_position, int direction, float speed)
{
    _grid = grid;
    _x_position = x_position;
    _y_position = y_position;
    _direction = direction;
    _speed = speed;
}

int Entity::getXPosition()
{
    return _x_position;
}

int Entity::getYPosition()
{
    return _y_position;
}

int Entity::getDirection()
{
    return _direction;
}

float Entity::getSpeed()
{
    return _speed;
}

float Entity::getFraction()
{
    return _fraction;
}

void Entity::move()
{
    // Wihtout subsection
    // switch (_direction)
    // {
    // case 'R':
    //     if (_grid[_x_position][(_y_position + 1) % 28] != 0)
    //     {
    //         _y_position++;
    //     }
    //     break;
    // case 'L':
    //     if (_grid[_x_position][(_y_position - 1) % 28] != 0)
    //     {
    //         _y_position--;
    //     }
    //     break;
    // case 'U':
    //     if (_grid[(_x_position - 1) % 36][_y_position] != 0)
    //     {
    //         _x_position--;
    //     }
    //     break;
    // case 'D':
    //     if (_grid[(_x_position + 1) % 36][_y_position] != 0)
    //     {
    //         _x_position++;
    //     }
    //     break;
    // default:
    //     break;
    // }
}

void Entity::updateDirection(int direction)
{
    _direction = direction;
}
