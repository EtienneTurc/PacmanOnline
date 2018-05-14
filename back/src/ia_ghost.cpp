#include "ia_ghost.h"

// TODO Tunnel

int lowestDirection(Pacman pacman, Ghost ghost) {
	Grid* grid = pacman.getGrid();
	std::vector<Virtual_ghost> virtual_ghosts;

	Grid* virtual_grid = new Grid();

	std::vector<int> directions = grid->checkIntersection(ghost.getXPosition(), ghost.getYPosition());

	//In case we are in a deadend
	if (directions.size() == 1) {
		return directions[0];
	}

	if (ghost.entityCollision(pacman)) {
		return ghost.getDirection();
	}

	virtual_grid->setCell(ghost.getXPosition(), ghost.getYPosition(), MARKED);
	for (int i = 0; i < directions.size(); i++) {
		Virtual_ghost v_ghost(directions[i],  grid,ghost.getXPosition(), ghost.getYPosition(), directions[i]);
		virtual_ghosts.push_back(v_ghost);
	}

	int count = 0;
	while (true) {
		// Move virtual_ghost
		count++;
		for (int i = 0; i < virtual_ghosts.size(); i++) {
			virtual_ghosts[i].virtualMove();
			bool val = virtual_ghosts[i].entityCollision(pacman);
			if (virtual_ghosts[i].entityCollision(pacman)) {
				return virtual_ghosts[i].getInitialDirection();
			}
		}

		// virtual_grid->displayGrid();

		//Update Virtual_ghost population
		int v_size = virtual_ghosts.size();
		for (int i = 0; i < v_size; i++) {
			Virtual_ghost v_ghost = virtual_ghosts[0];
			virtual_ghosts.erase(virtual_ghosts.begin());

			// Check if this cell is a new cell
			if (virtual_grid->getCell(v_ghost.getXPosition(), v_ghost.getYPosition()) != MARKED) {
				std::vector<int> directions = grid->checkIntersection(v_ghost.getXPosition(), v_ghost.getYPosition());
				virtual_grid->setCell(v_ghost.getXPosition(), v_ghost.getYPosition(), MARKED);

				for (int j = 0; j < directions.size(); j++) {
					if ((directions[j] + 2)%4 != v_ghost.getDirection()) {
						Virtual_ghost new_v_ghost = v_ghost;
						new_v_ghost.updateDirection(directions[j]);
						virtual_ghosts.push_back(new_v_ghost);
					}
				}
			}
		}
	}
}

int randomDirection(Entity entity) {
	Grid* grid = entity.getGrid();
	std::vector<int> directions = grid->checkIntersection(entity.getXPosition(), entity.getYPosition());

	float probaUTurn = 0.02;
	float p = ((float) rand() / (RAND_MAX));

	//Low probability of U-turn
	if (p < probaUTurn) {
		return (entity.getDirection()+2)%4;
	}

	directions.erase(std::remove(directions.begin(), directions.end(), (entity.getDirection()+2)%4), directions.end());
	float q = directions.size();
	float r = ((float) rand() / (RAND_MAX));

	for (int i = 0; i < q; i++) {
		if (r < (i+1)/q) {
			return directions[i];
		}
	}
}
