#ifndef GRID_H
#define GRID_H

#include <vector>
#include <iostream>
#include <cstdint>
#include "parameters.h"
#include "grid.h"

typedef std::vector<std::vector<uint8_t>> uint8_mat_t;

class Grid
{
public:
  void displayGrid();
  uint8_t getCell(int x_position, int y_position);

  void setCell(int x_position, int y_position, uint8_t value);
  bool checkWall(int x_position, int y_position, int direction);

  Grid();
  ~Grid(){};

private:
  uint8_mat_t _grid;
  int _sizeX;
  int _sizeY;
};

#endif //GRID_H
