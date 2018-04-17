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

    void eat();
    bool checkWall(int _x_position, int _y_position, int direction);

    Grid();
    ~Grid(){};

  private:
    uint8_mat_t _grid;
};

#endif //GRID_H
