#include <iostream>
#include <time.h>
#include <chrono>
#include "entity.h"
#include "game.h"
#include "parameters.h"
#include "safequeue.h"
#include "socket.h"
#include "route.h"

int main(int argc, char const *argv[]) {
	srand (time(NULL));

	Socket socket;
	socket.run();

	Games games {};
	while (true) {
		SafeQueue<std::pair<websocketpp::connection_hdl, std::string> >* client_queue = socket.getQueuePtr();
		std::vector<std::pair <websocketpp::connection_hdl, std::string>> instructions;

		if (client_queue->popAll(instructions)) {
			for (int i = 0; i < instructions.size(); i++) {
				Route route(instructions[i], &games, &socket);
				route.treatInstruction();
			}
		};

		for (int i = 0; i < games.size(); i++) {
			if (!games.at(i).second->gameOver()) {
				games.at(i).second->run();
				Route route(games.at(i), &socket);
				route.routeGetGame();
			}
		}

	}

	// std::cout << "Message du client : " << instructions.second << '\n';
	// socket.send(instructions);

	// Game game;
	// game.init();
	//
	// game.run();

	std::cout << "Game over\n";
	return 0;
}
