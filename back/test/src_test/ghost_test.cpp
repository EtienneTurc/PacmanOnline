#include "gtest/gtest.h"
#include "ghost_test.h"

/*
UNIT TESTS for GHOST class

Tested functions :
getTimeInJail, updateSpeed, inJail
*/

TEST_F(GhostTest, getTimeInJail) {
	EXPECT_EQ(0, _ghost->getTimeInJail());
}

TEST_F(GhostTest, updateSpeed) {
	_ghost->updateSpeed(3.5);
	EXPECT_EQ(3.5, _ghost->getSpeed());
}

TEST_F(GhostTest, inJail_false) {
	EXPECT_FALSE(_ghost->inJail());
}

TEST_F(GhostTest, inJail_true) {
	EXPECT_TRUE(_jailedGhost->inJail());
	EXPECT_EQ(X_CENTER, _jailedGhost->getXPosition());
	EXPECT_EQ(Y_CENTER, _jailedGhost->getYPosition());
	EXPECT_EQ(0, _jailedGhost->getTimeInJail());
}
