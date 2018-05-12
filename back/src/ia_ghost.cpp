#include "ia_ghost.h"

int lowestDirection(Pacman pacman, Ghost ghost) {
	Grid* grid = pacman.getGrid();
	std::vector<Virtual_ghost> virtual_ghosts;

	std::vector<int> directions = grid->checkIntersection(ghost.getXPosition(), ghost.getYPosition());

	//In case we are in a deadend
	if (directions.size() == 1) {
		return directions[0];
	}

	for (int i = 0; i < directions.size(); i++) {
		Virtual_ghost v_ghost(directions[i],  grid,ghost.getXPosition(), ghost.getYPosition(), directions[i]);
		virtual_ghosts.push_back(v_ghost);
	}

	while (true) {
		// Move virtual_ghost
		for (int i = 0; i < virtual_ghosts.size(); i++) {
			virtual_ghosts[i].virtualMove();
			if (virtual_ghosts[i].entityCollision(pacman)) {
				return virtual_ghosts[i].getInitialDirection();
			}
		}


		//Update Virtual_ghost population
		for (int i = 0; i < virtual_ghosts.size(); i++) {
			Virtual_ghost v_ghost = virtual_ghosts[0];
			virtual_ghosts.erase(virtual_ghosts.begin());
			std::vector<int> directions = grid->checkIntersection(virtual_ghosts[i].getXPosition(), virtual_ghosts[i].getYPosition());

			for (int j = 0; j < directions.size(); j++) {
				if ((directions[j] + 2)%4 != v_ghost.getDirection()) {
					v_ghost.updateDirection(directions[j]);
					virtual_ghosts.push_back(v_ghost);
				}
			}
		}
	}
}
