#include <iostream>
#include <time.h>
#include "entity.h"
#include "game.h"
#include "parameters.h"
#include "safequeue.h"
#include "socket.h"

int main(int argc, char const *argv[]) {
	srand (time(NULL));

	Socket socket;
	socket.run();

	while (true) {
		// std::cout << "Message du client" << '\n';
		SafeQueue<std::pair<websocketpp::connection_hdl, std::string> >* client_queue = socket.getQueuePtr();
		std::pair <websocketpp::connection_hdl, std::string> instructions;
		if (client_queue->pop(instructions)) {
			std::cout << "Message du client : " << instructions.second << '\n';
			socket.send(instructions);
		};
	}

	// Game game;
	// game.init();
	//
	// game.run();

	std::cout << "Game over\n";
	return 0;
}
