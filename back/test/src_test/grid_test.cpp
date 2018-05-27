#include "gtest/gtest.h"
#include "grid_test.h"
#include <vector>

/*
UNIT TEST for GRID class

Functions tested here :
getCell, SetCell, checkWall, checkIntersection

Missing:
displayGrid, setBigBalls
*/

TEST_F(GridTest, getCell_0) {
	EXPECT_EQ(0, _grid->getCell(0, 0));
}

TEST_F(GridTest, getCell_2) {
	EXPECT_EQ(2, _grid->getCell(1, 4));
}

TEST_F(GridTest, setCell) {
	_grid->setCell(0, 0, 3);
	EXPECT_EQ(3, _grid->getCell(0, 0));
}

TEST_F(GridTest, checkWall_true) {
	EXPECT_TRUE(_grid->checkWall(0, 0, DOWN));
}

TEST_F(GridTest, checkWall_false) {
}

TEST_F(GridTest, checkWall_error) {
	EXPECT_TRUE(_grid->checkWall(1, 4, 6));
}

TEST_F(GridTest, checkIntersection_size_4) {
	EXPECT_EQ(4, _grid->checkIntersection(6, 8).size());
}

TEST_F(GridTest, checkIntersection_size_2) {
	EXPECT_EQ(2, _grid->checkIntersection(1, 4).size());
}

TEST_F(GridTest, checkIntersection_size_empty) {
	EXPECT_EQ(0, _grid->checkIntersection(1, 1).size());
}

TEST_F(GridTest, checkIntersection_4_directions) {
	std::vector<int> results1 = _grid->checkIntersection(6, 8);
	std::vector<int> expected_result1;
	int res1[] = {1, 2, 3, 4};
	expected_result1.assign(res1, res1+4);
	EXPECT_TRUE(expected_result1 == results1);
}

TEST_F(GridTest, checkIntersection_2_directions) {
	std::vector<int> results2 = _grid->checkIntersection(1, 4);
	std::vector<int> expected_result2;
	int res2[] = {3, 4};
	expected_result2.assign(res2, res2+2);
	EXPECT_TRUE(expected_result2 == results2);
}
