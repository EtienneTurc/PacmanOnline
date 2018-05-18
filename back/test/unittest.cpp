#include "../headers/grid.h"
#include "../../../googletest-master/googletest/include/gtest/gtest.h"

namespace {

	TEST(GridTest, getCell) {
		Grid grid();
		EXPECT_EQ(0, 0);
	}

}
