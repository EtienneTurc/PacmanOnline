#include "game_test.h"

/*
UNIT TEST for GAME class

*/

TEST_F(GameTest, getPacmans_none) {
	EXPECT_EQ(0, _game->getPacmans()->size());
}

TEST_F(GameTest, getPacmans_addPacman) {
	_game->addPacman(*_pacman);
	EXPECT_EQ(1, _game->getPacmans()->size());
	std::vector<Pacman>* pacmans = _game->getPacmans();
	EXPECT_EQ(1, pacmans->at(0).getXPosition());
	EXPECT_EQ(4, pacmans->at(0).getYPosition());
	EXPECT_EQ(DOWN, pacmans->at(0).getDirection());
	EXPECT_EQ(1, pacmans->at(0).getSpeed());
}

TEST_F(GameTest, getGhosts_none) {
	EXPECT_EQ(0, _game->getGhosts()->size());
}

TEST_F(GameTest, getGhosts_addGhost) {
	_game->addGhost(*_ghost);
	EXPECT_EQ(1, _game->getGhosts()->size());
	std::vector<Ghost>* ghosts = _game->getGhosts();
	EXPECT_EQ(1, ghosts->at(0).getXPosition());
	EXPECT_EQ(4, ghosts->at(0).getYPosition());
	EXPECT_EQ(DOWN, ghosts->at(0).getDirection());
	EXPECT_EQ(1, ghosts->at(0).getSpeed());
}
