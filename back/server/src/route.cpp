#include <boost/algorithm/string.hpp>
#include "route.h"

Route::Route(Instructions instructions, Games* games, Socket* socket) {
	_hdl = instructions.first;
	_game = getGame(games);
	_socket = socket;

	std::vector<std::string> results;
	boost::split(results, instructions.second, [](char c){return c == ';';});

	_method = results[0];
	_data = {};
	for (int i = 1; i < results.size(); i++) {
		_data.push_back(results[i]);
	}
}

Route::Route(std::pair<websocketpp::connection_hdl, Game*> game, Socket* socket) {
	_hdl = game.first;
	_game = game.second;
	_socket = socket;
}

void Route::treatInstruction() {
	if (_method == "routeBeginGame") {
		routeBeginGame();
	} else if (_method == "routeGetGrid") {
		routeGetGrid();
	} else if (_method == "routeGetGame") {
		routeGetGame();
	} else if (_method == "routeGetNextAttackIn") {
		routeGetNextAttackIn();
	} else if (_method == "routeGetEntity") {
		routeGetGrid();
	} else if (_method == "routePostEntityDirection") {
		routePostEntityDirection();
	}
}

// Start a new game and send to the associated game
void Route::routeBeginGame() {
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
//Route;Pacman or Ghost?;Index in vector;Nbr of entities in the vector;XPosition;YPosition;Direction;Fraction;Score
void Route::routeGetEntity(Entity* entity, bool is_Pacman, int index_in_vector) {
	std::string data = "routeGetEntity;";
	if (is_Pacman) {
		data += "true;";
	} else {
		data += "false;";
	}

	data += std::to_string(index_in_vector);
	data += ";";
	data += std::to_string(_game->getPacmans()->size());
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
	std::pair <websocketpp::connection_hdl, std::string> instructions = std::make_pair(_hdl, "hi");
	_socket->send(instructions);
	std::vector<Pacman>* pacmans = _game->getPacmans();
	for (int i = 0; i < pacmans->size(); i++) {
		routeGetEntity(&pacmans->at(i), true, i);
	}

	std::vector<Ghost>* ghosts = _game->getGhosts();
	for (int i = 0; i < ghosts->size(); i++) {
		routeGetEntity(&ghosts->at(i), false, i);
	}

	routeGetGrid();
	routeGetNextAttackIn();
}

Game* Route::getGame(Games* games) {
	int j = -1;
	for (int i = 0; i < games->size(); i++) {
		if (!_hdl.owner_before(games->at(i).first) && !games->at(i).first.owner_before(_hdl)) {
			j = i;
			break;
		}
	}

	if (j != -1) {
		Game* game = games->at(j).second;
		return game;
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

//is Pacman ?;Index in vector;Direction (in _data)
void Route::routePostEntityDirection() {
	int index_in_vector = std::stoi(_data[1]);
	int direction = std::stoi(_data[2]);

	if (_data[0] == "true") {
		std::vector<Pacman>* pacmans = _game->getPacmans();
		Pacman* pacman = &pacmans->at(index_in_vector);
		pacman->pushInput(direction);
	} else {
		std::vector<Ghost>* ghosts = _game->getGhosts();
		Ghost* ghost = &ghosts->at(index_in_vector);
		ghost->pushInput(direction);
	}
}
