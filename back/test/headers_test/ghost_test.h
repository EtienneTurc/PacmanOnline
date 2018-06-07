#ifndef GHOST_TEST_H
#define GHOST_TEST_H

#include "grid.h"
#include "ghost.h"
#include "parameters.h"

class GhostTest : public ::testing::Test {
	protected:
		void SetUp(){
			_grid = new Grid;
			_ghost = new Ghost(_grid, 1, 4, DOWN, 1, 0, 0, 1);
			_jailedGhost = new Ghost(_grid, 1, 4, DOWN, 1, 0, 1, 1);
		};

		Grid* _grid;
		Ghost* _ghost;
		Ghost* _jailedGhost;
};

#endif
