#include "entity.h"

Entity::Entity(Grid *grid, int x_position, int y_position, int direction, float speed)
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

void Entity::move(float delta_time)
{
    // Update the direction
    if (_event)
    {
        updateDirection(_event);
    }

    // Update the current position
    switch (_direction)
    {
    case LEFT:
        if (_fraction > 1)
        {
            _x_position--;
        }
        updateFraction(delta_time);
        break;
    case RIGHT:
        if (_fraction > 1)
        {
            _x_position++;
        }
        updateFraction(delta_time);
        break;
    case UP:
        if (_fraction > 1)
        {
            _y_position--;
        }
        updateFraction(delta_time);
        break;
    case DOWN:
        if (_fraction > 1)
        {
            _y_position++;
        }
        updateFraction(delta_time);
        break;
    default:
        break;
    }
}

void Entity::updateDirection(int direction)
{
    if (!grid.checkWallByDirection(_x_position, _y_position, direction))
    {
        _direction = direction;
    }
}

void pushInput(int direction)
{
    _event = direction;
}

void updateFraction(float delta_time) {
    _fraction = _fraction + delta_time
    while (_fraction > 1) 
    {
     _fraction = _fraction - 1;   
    }
}