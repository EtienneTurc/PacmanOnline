#include <iostream>
#include "entity.h"
#include "game.h"
#include "parameters.h"

int main(int argc, char const *argv[]) {

	Game game;
	game.init();

	game.run();

	std::cout << "Game over\n";
	return 0;
}
