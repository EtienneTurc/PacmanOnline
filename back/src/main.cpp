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
		}

		std::vector<int> to_suppress = {};
		for (int i = 0; i < games.size(); i++) {
			if (!games.at(i).second->gameOver()) {
				games.at(i).second->run();
				Route route(games.at(i), &socket);
				route.routeGetGame();
			} else {
				to_suppress.push_back(i);
			}
		}

		for (int i = (to_suppress.size() -1) ; i >= 0; i--) {
			std::pair<websocketpp::connection_hdl, std::string> game_over = make_pair(games[i].first, "routeGameOver");
			socket.send(game_over);
			games.erase(games.begin()+i);
		}
	}

	// std::cout << "Message du client : " << instructions.second << '\n';
	// socket.send(instructions);

	// Game game;
	// game.init();
	//
	// game.run();

	// std::cout << "Game over\n";
	return 0;
}
