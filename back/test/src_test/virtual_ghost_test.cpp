#include "virtual_ghost_test.h"

/*
UNIT TESTS for VIRTUAL GHOST class

functions tested : getInitialDirection
*/

TEST_F(VirtualGhostTest, getInitialDirection) {
	EXPECT_EQ(UP, _vghost->getInitialDirection());
}
