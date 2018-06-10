#ifndef GAME_H
#define GAME_H

#include <vector>
#include <iostream>
#include <stdlib.h>
#include <chrono>

#include "grid.h"
#include "parameters.h"
#include "entity.h"
#include "ghost.h"
#include "pacman.h"
#include "virtual_ghost.h"
#include "ia_ghost.h"

class Game {
public:
	std::vector<Pacman>* getPacmans();
	std::vector<Ghost>* getGhosts();
	Grid* getGrid();
	int getTimeToFlee();

	void addGhost(Ghost new_ghost);
	void addPacman(Pacman new_pacman);

	void displayEntities();
	void init();
	void run();
	bool gameOver();
	void eatGhostsIfAllowed();

	Game();
	~Game() {};

private:
	int _time_to_flee;
	std::vector<Pacman> _pacmans;
	std::vector<Ghost> _ghosts;
	Grid* _grid;

	void updateGhostsStatus(int new_time_to_flee);
};

#endif
