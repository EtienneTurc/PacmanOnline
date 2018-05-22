#include <iostream>
#include <time.h>
#include "entity.h"
#include "game.h"
#include "parameters.h"
// #include "safequeue.h"
// #include "socket.h"

int main(int argc, char const *argv[]) {
	srand (time(NULL));

	// Socket server;
	// server.run();

	std::cout << "hi\n";

	Game game;
	game.init();

	game.run();

	std::cout << "Game over\n";
	return 0;
}
