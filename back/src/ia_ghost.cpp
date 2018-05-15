#include "ia_ghost.h"
#include <chrono>
#include <thread>

// TODO Tunnel
// The ranking indicates the choice of the best way to choose (ie 0 corresponds to the best, 1 corresponds to the second best direction)
int lowestDirection(Pacman pacman, Ghost ghost, int ranking) {
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
		int v_size = virtual_ghosts.size();
		int index_to_delete = v_size;
		for (int i = 0; i < virtual_ghosts.size(); i++) {
			virtual_ghosts[i].virtualMove();
			bool val = virtual_ghosts[i].entityCollision(pacman);
			if (virtual_ghosts[i].entityCollision(pacman)) {
				if (count == ranking) {
					return virtual_ghosts[i].getInitialDirection();
				}  else {
					count++;
					index_to_delete = i;
				}
			}
		}

		if (index_to_delete != v_size) {
			virtual_ghosts.erase(virtual_ghosts.begin() + index_to_delete);
		}

		// virtual_grid->displayGrid();

		//Update Virtual_ghost population
		v_size = virtual_ghosts.size();
		for (int i = 0; i < v_size; i++) {
			Virtual_ghost v_ghost = virtual_ghosts[0];
			virtual_ghosts.erase(virtual_ghosts.begin());

			// Check if this cell is a new cell
			if (virtual_grid->getCell(v_ghost.getXPosition(), v_ghost.getYPosition()) != MARKED) {
				std::vector<int> directions = grid->checkIntersection(v_ghost.getXPosition(), v_ghost.getYPosition());
				virtual_grid->setCell(v_ghost.getXPosition(), v_ghost.getYPosition(), MARKED);

				for (int j = 0; j < directions.size(); j++) {
					if (((directions[j] + 1)%4 +1) != v_ghost.getDirection()) {
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

	float p = ((float) rand() / (RAND_MAX));

	//Low probability of U-turn
	if (p < PROBA_U_TURN) {
		return ((entity.getDirection()+1)%4 +1);
	}

	directions.erase(std::remove(directions.begin(), directions.end(), ((entity.getDirection()+1)%4) +1), directions.end());
	float size = directions.size();
	float random = ((float) rand() / (RAND_MAX));

	for (int i = 0; i < size; i++) {
		if (random < (i+1)/size) {
			return directions[i];
		}
	}
}

int lowestDirectionToIntersection(Pacman pacman, Ghost ghost) {
	Pacman virtual_pacman = pacman;
	Grid* grid = virtual_pacman.getGrid();

	std::vector<int> directions = grid->checkIntersection(virtual_pacman.getXPosition(), virtual_pacman.getYPosition());

	int size = directions.size();
	int direction = virtual_pacman.getDirection();
	while (size < 3) {
		for (int i = 0; i < directions.size(); i++) {
			if (((directions[i] + 1)%4+1) != virtual_pacman.getDirection()) {
				direction = directions[i];
			}
		}
		virtual_pacman.updateDirection(direction);

		virtual_pacman.virtualMove();
		directions = grid->checkIntersection(virtual_pacman.getXPosition(), virtual_pacman.getYPosition());
		size = directions.size();
	}

	return lowestDirection(virtual_pacman, ghost);
}

int lowestDirectionUntilRandom(Pacman pacman, Ghost ghost) {
	int distance = ghost.distanceTo(pacman.getXPosition(), pacman.getYPosition());

	if (distance > RANDOM_RANGE) {
		return lowestDirection(pacman, ghost);
	} else {
		return randomDirection(ghost);
	}
}
