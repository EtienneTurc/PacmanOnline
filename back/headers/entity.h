#ifndef ENTITY_H
#define ENTITY_H

#include <cstdint>
#include "grid.h"
#include "parameters.h"

class Entity {
public:

	int getXPosition();
	int getYPosition();
	int getDirection();
	float getSpeed();
	float getFraction();
	int getScore();
	Grid* getGrid();

	bool entityCollision(Entity entity);

	void pushInput(int direction);
	void move(float delta_time);
	void virtualMove();

	void updateDirection(int direction);
	void updateFraction(float delta_time);

	Entity(Grid* grid, int x_position, int y_position, int direction, float speed, int score);
	~Entity() {}

protected:
	Grid* _grid;
	int _x_position;
	int _y_position;
	int _direction;
	float _speed;
	float _fraction;
	int _event;
	int _score;
};

#endif
