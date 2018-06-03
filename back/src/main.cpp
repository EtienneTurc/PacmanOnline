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

	int tref = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now().time_since_epoch()).count();
	int t = tref + 1;

	Socket socket;
	socket.run();

	Games games {};
	while (true) {
		t = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now().time_since_epoch()).count();
		if (t >= tref+1) {
			tref = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now().time_since_epoch()).count();
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
