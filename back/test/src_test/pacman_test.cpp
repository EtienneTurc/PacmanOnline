#include "gtest/gtest.h"
#include "pacman_test.h"

/*
UNIT TEST for PACMAN class

Tested functions:
eat

Missing : eat a ghost
*/

TEST_F(PacmanTest, eat_track) {
	_grid->setCell(1, 4, TRACK);
	_pacman->eat();
	EXPECT_EQ(0, _pacman->getScore());
}

TEST_F(PacmanTest, eat_small_ball) {
	_grid->setCell(1, 4, SMALL_BALL);
	_pacman->eat();
	EXPECT_EQ(SCORE_SMALL_BALL, _pacman->getScore());
}

TEST_F(PacmanTest, eat_big_ball) {
	_grid->setCell(1, 4, BIG_BALL);
	_pacman->eat();
	EXPECT_EQ(SCORE_BIG_BALL, _pacman->getScore());
}

TEST_F(PacmanTest, eat_fruit) {
	_grid->setCell(1, 4, FRUIT);
	_pacman->eat();
	EXPECT_EQ(SCORE_FRUIT, _pacman->getScore());
}
