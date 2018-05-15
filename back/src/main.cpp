#include <iostream>
#include <time.h>
#include "entity.h"
#include "game.h"
#include "parameters.h"

int main(int argc, char const *argv[]) {
	srand (time(NULL));

	Game game;
	game.init();

	game.run();

	std::cout << "Game over\n";
	return 0;
}
