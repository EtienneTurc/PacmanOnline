#include <vector>
#include <iostream>

#ifndef GRID_H
#define GRID_H

typedef std::vector<std::vector<uint8_t> > uint8_mat_t;

class Grid
{
public:
    void eat();
    void displayGrid();
    Grid();
    ~Grid() {};
private:
    uint8_mat_t _grid;
};


#endif //GRID_H
