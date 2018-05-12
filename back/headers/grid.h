#ifndef GRID_H
#define GRID_H

#include <vector>
#include <iostream>
#include <cstdint>
#include "parameters.h"
#include "grid.h"

typedef std::vector<std::vector<uint8_t>> uint8_mat_t;

const std::string red("\033[0;31m");
const std::string green("\033[1;32m");
const std::string yellow("\033[1;33m");
const std::string cyan("\033[0;36m");
const std::string magenta("\033[0;35m");
const std::string reset("\033[0m");


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
