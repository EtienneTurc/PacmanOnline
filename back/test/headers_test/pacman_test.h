#ifndef PACMAN_TEST_H
#define  PACMAN_TEST_H

#include "grid.h"
#include "pacman.h"

class PacmanTest : public ::testing::Test {
	protected:
		void SetUp() {
			_grid = new Grid;
			_pacman = new Pacman(_grid, 1, 4, DOWN, 1);
		};

		Pacman* _pacman;
		Grid* _grid;
};

#endif
