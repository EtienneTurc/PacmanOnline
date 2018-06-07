#ifndef GAME_TEST_H
#define  GAME_TEST_H

#include "game.h"
#include "gtest/gtest.h"

class GameTest : public ::testing::Test {
	protected:
		virtual void SetUp() {
			_game = new Game;
			_grid = new Grid;
			_ghost = new Ghost(_grid, 1, 4, DOWN, 1, 0, 0, 1);
			_pacman = new Pacman(_grid, 1, 4, DOWN, 1);
		};
		Game* _game;
		Pacman* _pacman;
		Ghost* _ghost;
		Grid* _grid;
};

#endif
