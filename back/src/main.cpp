#include <iostream>
#include <time.h>
#include <chrono>
#include "entity.h"
#include "game.h"
#include "parameters.h"
#include "safequeue.h"
#include "socket.h"
#include "route.h"


// This is the place where the magic happends
// The server is activating there
// There is a vector containing all the games with the associated client
int main() {
	srand (time(NULL));

	// Initializing the server
	Socket socket;
	socket.run();

	// Initializing the variables
	Games games {};
	std::chrono::milliseconds now;
	std::chrono::milliseconds now_time;
	std::chrono::milliseconds delta_time;
	SafeQueue<websocketpp::connection_hdl>* closed_connections;
	std::vector<websocketpp::connection_hdl> to_close;
	SafeQueue<std::pair<websocketpp::connection_hdl, std::string> >* client_queue;
	std::vector<std::pair <websocketpp::connection_hdl, std::string>> instructions;
	std::vector<int> to_suppress;
	std::pair<websocketpp::connection_hdl, std::string> game_over;
	std::pair<websocketpp::connection_hdl, std::string> has_won;

	// The core of the server
	while (true) {
		now = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch());

		// Looking for games that closed their websocket connection
		closed_connections = socket.getClosedConnectionsPtr();
		client_queue = socket.getQueuePtr();
		to_suppress = {};
		to_close = {};
		if (closed_connections->popAll(to_close)) {
			for (unsigned int j = 0; j < to_close.size(); j++) {
				for (unsigned int i = 0; i < games.size(); i++) {
					if (!to_close[j].owner_before(games[i].first) && !games[i].first.owner_before(to_close[j])) {
						to_suppress.push_back(i);
					}
				}
			}
		}

		// Suprresing these games from the vector of all the games
		for (int i = (to_suppress.size() -1) ; i >= 0; i--) {
			games.erase(games.begin() + to_suppress[i]);
		}

		// Treat the instruction of the player (if there is any)
		instructions = {};
		if (client_queue->popAll(instructions)) {
			for (unsigned int i = 0; i < instructions.size(); i++) {
				Route route(instructions[i], &games, &socket);
				route.treatInstruction();
			}
		}

		// Run the game (Check if the game is over or not)
		to_suppress = {};
		for (unsigned int i = 0; i < games.size(); i++) {
			if (games[i].second->getGrid()->noMoreBalls()) {
				has_won = make_pair(games[i].first, "routeHasWon");
				socket.send(has_won);
				to_suppress.push_back(i);
			} else if (!games[i].second->gameOver()) {
				games[i].second->run();
				Route route(games[i], &socket);
				route.routeGetGame();
			} else {
				game_over = make_pair(games[i].first, "routeGameOver");
				socket.send(game_over);
				to_suppress.push_back(i);
			}
		}

		// Supressing games that are done (winning or losing games)
		for (int i = (to_suppress.size() -1) ; i >= 0; i--) {
			games.erase(games.begin() + to_suppress[i]);
		}

		// The tick of the server is 40 milliseconds => 25 frame/s (could go higher but it useless)
		now_time = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch());
		delta_time = std::chrono::milliseconds(40);
		std::this_thread::sleep_for(std::chrono::milliseconds(delta_time));
	}
	return 0;
}
