#ifndef ROUTE_H
#define ROUTE_H

#include <iostream>
#include "game.h"
#include "socket.h"

typedef std::vector<std::pair<websocketpp::connection_hdl, Game*>> Games;
typedef std::pair <websocketpp::connection_hdl, std::string> Instructions;

class Route {
public:
	void treatInstruction();

	void routeBeginGame(std::vector<std::string>* data);
	void routeGetGrid();
	void routeGetEntity(Entity* entity, bool is_Pacman, int index_in_vector);
	void routeGetNextAttackIn();
	void routeGetGame();

	Route(Instructions instructions, Games* games, Socket* socket);
	~Route(){};

private:
	websocketpp::connection_hdl _hdl;
	std::string _instructions;
	Game* _game;
	Socket* _socket;

	Game* getGame(Games* games);
	Game* createGame(Games* games);
};

#endif
