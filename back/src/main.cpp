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
		std::chrono::milliseconds now = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch());

		SafeQueue<websocketpp::connection_hdl>* closed_connections = socket.getClosedConnectionsPtr();
		std::vector<websocketpp::connection_hdl> to_close;
		SafeQueue<std::pair<websocketpp::connection_hdl, std::string> >* client_queue = socket.getQueuePtr();
		std::vector<std::pair <websocketpp::connection_hdl, std::string>> instructions;

		std::vector<int> to_suppress = {};
		if (closed_connections->popAll(to_close)) {
			for (int j = 0; j < to_close.size(); j++) {
				for (int i = 0; i < games.size(); i++) {
					if (!to_close[j].owner_before(games[i].first) && !games[i].first.owner_before(to_close[j])) {
						to_suppress.push_back(i);
					}
				}
			}
		}

		for (int i = (to_suppress.size() -1) ; i >= 0; i--) {
			games.erase(games.begin()+i);
		}

		if (client_queue->popAll(instructions)) {
			for (int i = 0; i < instructions.size(); i++) {
				Route route(instructions[i], &games, &socket);
				route.treatInstruction();
			}
		}

		to_suppress = {};
		for (int i = 0; i < games.size(); i++) {
			if (!games.at(i).second->gameOver()) {
				games.at(i).second->run();
				Route route(games.at(i), &socket);
				route.routeGetGame();
			} else {
				std::pair<websocketpp::connection_hdl, std::string> game_over = make_pair(games[i].first, "routeGameOver");
				socket.send(game_over);
				to_suppress.push_back(i);
			}
			if (games.at(i).second->getGrid()->noMoreBalls()) {
				std::cout << "Has Won" << '\n';
				std::pair<websocketpp::connection_hdl, std::string> has_won = make_pair(games[i].first, "routeHasWon");
				socket.send(has_won);
				to_suppress.push_back(i);
			}
		}

		for (int i = (to_suppress.size() -1) ; i >= 0; i--) {
			games.erase(games.begin()+i);
		}

		std::chrono::milliseconds now_time = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch());
		std::chrono::milliseconds delta_time = std::chrono::milliseconds(40);
		while (now_time < now + delta_time) {
			now_time = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch());
		}
	}
	return 0;
}
