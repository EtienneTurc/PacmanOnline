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

	void setXPosition(int x_position);
	void setYPosition(int y_position);
	void setInputTime(int input_time);
	void setFraction(float fraction);
	void addScore(int score_to_add);

	bool entityCollision(Entity entity);
	int distanceTo(int x_position, int y_position);

	void pushInput(int direction);
	void move(float delta_time);
	void virtualMove();

	void updateDirection(int direction);
	void updateFraction();

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
	int _input_time;
};

#endif
