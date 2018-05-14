#ifndef GAME_H
#define GAME_H

#include <vector>
#include <iostream>
#include <stdlib.h>

#include "grid.h"
#include "parameters.h"
#include "entity.h"
#include "ghost.h"
#include "pacman.h"
#include "virtual_ghost.h"
#include "ia_ghost.h"

class Game {
public:
	int getGhostsStatus();
	std::vector<Pacman> getPacmans();
	std::vector<Ghost> getGhosts();

	void updateGhostsStatus(int new_ghosts_status);

	void addGhost(Ghost new_ghost);
	void addPacman(Pacman new_pacman);

	void displayEntities();

	//bool gameOver();

	void init();
	void run();

	Game();
	~Game() {};

private:
	int _ghosts_status;
	std::vector<Pacman> _pacmans;
	std::vector<Ghost> _ghosts;
	Grid* _grid;
};

#endif
