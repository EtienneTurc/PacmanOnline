#include "entity.h"

Entity::Entity(Grid *grid, int x_position, int y_position, int direction, float speed, int score)
{
    _grid = grid;
    _x_position = x_position;
    _y_position = y_position;
    _direction = direction;
    _speed = speed;
    _fraction = 1 / 2;
    _event = 0;
    _score = score;
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

int Entity::getScore()
{
    return _score;
}

void Entity::pushInput(int direction)
{
    _event = direction;
}

void Entity::updateDirection(int direction)
{
    if (!_grid->checkWall(_x_position, _y_position, direction))
    {
        _direction = direction;
    }
}

void Entity::updateFraction(float delta_time)
{
    // _fraction can not overtake 0.5 if there is a wall
    if (_grid->checkWall(_x_position, _y_position, _direction) && _fraction > 0.5)
    {
        _fraction = 0.5;
    }
    else
    {
        _fraction = _fraction + delta_time * _speed;
        while (_fraction > 1)
        {
            _fraction = _fraction - 1;
        }
    }
}

void Entity::move(float delta_time)
{
    // Update the direction
    if (_event)
    {
        updateDirection(_event);
        _event = 0;
    }

    // Check if there is a wall in front
    if (!_grid->checkWall(_x_position, _y_position, _direction) || _fraction < 0.5)
    {
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
}
