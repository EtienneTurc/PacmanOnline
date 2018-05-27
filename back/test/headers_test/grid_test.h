#ifndef GRID_TEST_H
#define  GRID_TEST_H

#include "grid.h"
#include "parameters.h"

class GridTest : public ::testing::Test {
	protected:
		virtual void SetUp() {
			_grid = new Grid;
		};

		Grid* _grid;
};

#endif
