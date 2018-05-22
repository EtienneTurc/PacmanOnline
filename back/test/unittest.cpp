#include "../headers/grid.h"
#include "../../../googletest-master/googletest/include/gtest/gtest.h"

namespace {

	TEST(GridTest, getCell) {
		Grid* grid = new Grid;
		EXPECT_EQ(0, grid->getCell(0, 0));
	}
	TEST(GridTest, setCell) {
		Grid* grid = new Grid;
		grid->setCell(0, 0, 3);
		EXPECT_EQ(3, grid->getCell(0, 0));
	}

}
