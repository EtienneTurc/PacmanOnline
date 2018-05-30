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

	void routeBeginGame();
	void routeGetGrid();
	void routeGetEntity(Entity* entity, bool is_Pacman, int index_in_vector);
	void routeGetNextAttackIn();
	void routeGetGame();

	void routePostEntityDirection();

	Route(Instructions instructions, Games* games, Socket* socket);
	Route(std::pair<websocketpp::connection_hdl, Game*> game, Socket* socket);
	~Route(){};

private:
	websocketpp::connection_hdl _hdl;
	Game* _game;
	Socket* _socket;
	std::string _method;
	std::vector<std::string> _data;

	Game* getGame(Games* games);
	Game* createGame(Games* games);
};

#endif
