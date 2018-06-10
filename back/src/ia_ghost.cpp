#include "ia_ghost.h"
#include <chrono>
#include <thread>

// Pool of functions that returns a direction in order to guide the ghost
// lowestDirection and lowestDirectionToIntersection works very well together (it complicates a lot the game and so having 2 other string ias is not a good call, because in that case the game would be impossible). At this point, only win for an average of 200 games played (by different people)


// Function returning the best direction
// The best direction is determined by the lowest distance to travel to the pacman
int lowestDirection(Pacman pacman, Ghost ghost) {

	//Creating a virtual grid and virtual ghosts that are going to scout for the pacman
	Grid* grid = pacman.getGrid();
	std::vector<Virtual_ghost> virtual_ghosts;

	Grid* virtual_grid = new Grid();

	std::vector<int> directions = grid->checkIntersection(ghost.getXPosition(), ghost.getYPosition());

	//In case we are in a deadend
	if (directions.size() == 1) {
		return directions[0];
	}

	// If the pacman has been found
	if (ghost.entityCollision(pacman)) {
		return ghost.getDirection();
	}

	// Create all the virtual ghosts going in all the possible starting from the current position of the given ghost
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
				return virtual_ghosts[i].getInitialDirection();
			}
		}

		// Uncomment these two lines if you want to see the virtual ghosts in action (it will appear in the terminal)
		// virtual_grid->displayGrid();
		// std::this_thread::sleep_for (std::chrono::milliseconds(100));

		//Update Virtual_ghost population
		v_size = virtual_ghosts.size();
		for (int i = 0; i < v_size; i++) {
			Virtual_ghost v_ghost = virtual_ghosts[0];
			virtual_ghosts.erase(virtual_ghosts.begin());

			// Check if this cell is a new cell (if it's not the virtual ghosts is supressed)
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

// Function that returs a direction
// The direction usually change at intersections because the probability of U- turn is really low
int randomDirection(Entity entity) {

	if (entity.getFraction() < 0.30 ) {
		// Get the possible directions
		Grid* grid = entity.getGrid();
		std::vector<int> directions = grid->checkIntersection(entity.getXPosition(), entity.getYPosition());

		//Low probability of U-turn
		float p = ((float) rand() / (RAND_MAX));
		if (p < PROBA_U_TURN) {
			return ((entity.getDirection()+1)%4 +1);
		}

		// Deleting the U-Turn direction from all the possible directions
		directions.erase(std::remove(directions.begin(), directions.end(), ((entity.getDirection()+1)%4) +1), directions.end());

		// Choosing the next direction
		float size = directions.size();
		float random = ((float) rand() / (RAND_MAX));
		for (int i = 0; i < size; i++) {
			if (random < (i+1)/size) {
				return directions[i];
			}
		}
	}
}

// Function that returns a direction
// It's basically the same algorithm than the lowestDirection one, however it's simulates a pacman moving forward to the next intersection, and the ghost determine the best way to go there
int lowestDirectionToIntersection(Pacman pacman, Ghost ghost) {

	// Initializing a virtual pacman
	Pacman virtual_pacman = pacman;
	Grid* grid = virtual_pacman.getGrid();

	// Moving the virtual pacman to the next intersection (in his direction) and stop it when done
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

// Function that returns a direction
// Function that allow the ghost to go near the pacman and then to be random (with the random function defined above)
int lowestDirectionUntilRandom(Pacman pacman, Ghost ghost) {
	int distance = ghost.distanceTo(pacman.getXPosition(), pacman.getYPosition());

	if (distance > RANDOM_RANGE) {
		return lowestDirection(pacman, ghost);
	} else {
		return randomDirection(ghost);
	}
}
