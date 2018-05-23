#ifndef GRID_H
#define GRID_H

#include <vector>
#include <iostream>
#include <cstdint>
#include "parameters.h"

#define RED "\033[0;31m"
#define GREEN "\033[1;32m"
#define YELLOW "\033[1;33m"
#define WALL "\033[38;5;234m"
#define STREET "\033[38;5;247m"
#define RESET "\033[0m"

typedef std::vector<std::vector<uint8_t>> uint8_mat_t;

class Grid
{
public:
	void displayGrid();
	uint8_t getCell(int x_position, int y_position);

	void setCell(int x_position, int y_position, uint8_t value);
	bool checkWall(int x_position, int y_position, int direction);
	std::vector<int> checkIntersection(int x_position, int y_position);

	Grid();
	~Grid(){};

private:
	uint8_mat_t _grid;
	int _sizeX;
	int _sizeY;
};

#endif //GRID_H
