#include "grid.h"
#include "gtest/gtest.h"

TEST(GridTest, getCell) {
	Grid* grid = new Grid;
	EXPECT_EQ(0, grid->getCell(0, 0));
}
TEST(GridTest, setCell) {
	Grid* grid = new Grid;
	grid->setCell(0, 0, 3);
	EXPECT_EQ(3, grid->getCell(0, 0));
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
