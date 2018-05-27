#ifndef ROUTE_H
#define ROUTE_H

#include <iostream>
#include "game.h"
#include "socket.h"

typedef std::vector<std::pair<websocketpp::connection_hdl, Game*>> Games;
typedef std::pair <websocketpp::connection_hdl, std::string> Instructions;

void treatInstruction(Instructions instructions, Games* games);
void routeBeginGame(websocketpp::connection_hdl hdl, std::vector<std::string>* data, Games* games);
// void getGrid()

#endif
