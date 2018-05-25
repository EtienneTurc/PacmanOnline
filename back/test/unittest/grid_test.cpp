#include "grid.h"
#include "gtest/gtest.h"
#include "parameters.h"
#include "grid_test.h"
#include <vector>

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
	EXPECT_EQ(true, _grid->checkWall(0, 0, DOWN));
}

TEST_F(GridTest, checkWall_false) {
	EXPECT_EQ(false, _grid->checkWall(3, 4, LEFT));
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

	std::vector<int> results2 = _grid->checkIntersection(1, 4);
	std::vector<int> expected_result2;
	int res2[] = {3, 4};
	expected_result1.assign(res2, res1+2);
	EXPECT_TRUE(expected_result2 == results2);
}
