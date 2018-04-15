#include <vector>
#include <IOSTREAM>

#ifndef GRID_H
#define GRID_H

typedef std::vector<std::vector<uint8> > uint8_mat_t;

class Grid
{
public:
    void eat();
    void displayGrid();
    Grid();
    ~Grid();
private:
    uint8_mat_t _grid;
};


#endif //GRID_H
