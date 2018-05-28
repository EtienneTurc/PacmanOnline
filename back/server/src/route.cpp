#include <boost/algorithm/string.hpp>
#include "route.h"

Route::Route(Instructions instructions, Games* games, Socket* socket) {
	_hdl = instructions.first;
	_instructions = instructions.second;
	_game = getGame(games);
	_socket = socket;
}

void Route::treatInstruction() {

	std::vector<std::string> results;
	boost::split(results, _instructions, [](char c){return c == ';';});

	std::string method = results[0];
	std::vector<std::string> data;
	for (int i = 1; i < results.size(); i++) {
		data.push_back(results[i]);
	}

	if (method == "routeBeginGame") {
		routeBeginGame(&data);
	} else if (method == "routeGetGrid") {
		routeGetGrid();
	} else if (method == "routeGetGame") {
		routeGetGame();
	} else if (method == "routeGetNextAttackIn") {
		routeGetNextAttackIn();
	} else if (method == "routeGetEntity") {
		routeGetGrid();
	}
}

// Start a new game and send to the associated game
void Route::routeBeginGame(std::vector<std::string>* data) {
	_game->init();
	routeGetGame();
}

//Route;SizeX;SizeY;Grid
void Route::routeGetGrid() {
	std::string data = "routeGetGrid;";

	Grid* grid = _game->getGrid();
	int sizeX = grid->getSizeX();
	int sizeY = grid->getSizeY();

	data += std::to_string(sizeX);
	data += ";";
	data += std::to_string(sizeY);
	data += ";";

	for (int i = 0; i < sizeX; i++) {
		for (int j = 0; j < sizeY; j++) {
			data += std::to_string(grid->getCell(i, j));
			data += ";";
		}
	}

	std::pair <websocketpp::connection_hdl, std::string> instructions = std::make_pair(_hdl, data);
	_socket->send(instructions);
}

// index_in_vector is the index of the entity in the vector -> it identifies it
//Route;Pacman or Ghost?;Index in vector;XPosition;YPosition;Direction;Fraction;Score
void Route::routeGetEntity(Entity* entity, bool is_Pacman, int index_in_vector) {
	std::string data = "routeGetEntity;";
	if (is_Pacman) {
		std::string data = "Pacman;";
	} else {
		std::string data = "Ghost;";
	}

	data += std::to_string(index_in_vector);
	data += ";";
	data += std::to_string(entity->getXPosition());
	data += ";";
	data += std::to_string(entity->getYPosition());
	data += ";";
	data += std::to_string(entity->getDirection());
	data += ";";
	data += std::to_string(entity->getFraction());
	data += ";";
	data += std::to_string(entity->getScore());
	data += ";";

	std::pair <websocketpp::connection_hdl, std::string> instructions = std::make_pair(_hdl, data);
	_socket->send(instructions);
}

//Route;next_attack_in
void Route::routeGetNextAttackIn() {
	std::string data = "routeGetNextAttackIn;";

	data += std::to_string(_game->getTimeToFlee());
	data += ";";

	std::pair <websocketpp::connection_hdl, std::string> instructions = std::make_pair(_hdl, data);
	_socket->send(instructions);
}

void Route::routeGetGame() {
	std::vector<Pacman> pacmans = _game->getPacmans();
	for (int i = 0; i < pacmans.size(); i++) {
		routeGetEntity(&pacmans[i], true, i);
	}

	std::vector<Ghost> ghosts = _game->getGhosts();
	for (int i = 0; i < ghosts.size(); i++) {
		routeGetEntity(&ghosts[i], false, i);
	}

	routeGetGrid();
	routeGetNextAttackIn();
}

Game* Route::getGame(Games* games) {
	int j = -1;
	for (int i = 0; i < games->size(); i++) {
		if (_hdl.owner_before(games->at(i).first)) {
			j = i;
			break;
		}
	}

	if (j != -1) {
		return games->at(j).second;
	} else {
		return createGame(games);
	}
}

Game* Route::createGame(Games* games) {
	Game* new_game = new Game;
	std::pair<websocketpp::connection_hdl, Game*> game = std::make_pair(_hdl, new_game);

	games->push_back(game);

	return new_game;
}
