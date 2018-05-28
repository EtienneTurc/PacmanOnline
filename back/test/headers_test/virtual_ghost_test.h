#ifndef VIRTUAL_GHOST_TEST
#define VIRTUAL_GHOST_TEST

#include "gtest/gtest.h"
#include "virtual_ghost.h"
#include "grid.h"
#include "parameters.h"

class VirtualGhostTest : public ::testing::Test {
protected:
	virtual void SetUp() {
		_grid = new Grid;
		_vghost = new Virtual_ghost(UP, _grid, 1, 4, DOWN);
	};
	Virtual_ghost* _vghost;
	Grid* _grid;
};

#endif
