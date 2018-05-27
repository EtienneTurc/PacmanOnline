#include <boost/algorithm/string.hpp>
#include "route.h"

void treatInstruction(Instructions instructions, Games* games) {

	std::vector<std::string> results;
	boost::split(results, instructions.second, [](char c){return c == ';';});

	std::string route = results[0];
	std::vector<std::string> data;
	for (int i = 1; i < results.size(); i++) {
		data.push_back(results[i]);
	}


	if (route == "routeBeginGame") {
		routeBeginGame(instructions.first, &data, games);
	// } else if () {
		// case "routeGetGrid":
		// 	routeGetGrid();
	}
}

void routeBeginGame(websocketpp::connection_hdl hdl, std::vector<std::string>* data, Games* games) {

	int j = -1;
	for (int i = 0; i < games->size(); i++) {
		if (hdl.owner_before(games->at(i).first)) {
			j = i;
			break;
		}
	}

	Game* new_game = new Game;
	std::pair<websocketpp::connection_hdl, Game*> game = std::make_pair(hdl, new_game);

	if (j == -1) {
		games->push_back(game);
	} else {
		games->at(j) = game;
	}

	new_game->init();
	new_game->displayEntities();
}
