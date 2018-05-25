#include "socket.h"
#include <iostream>
#include <boost/bind/bind.hpp>

#define SOCKET_PORT 8080

Socket::Socket () {
	_server.init_asio();
	_is_alive = false;

	// Bind callbacks to class methods
	_server.set_open_handler(bind(&Socket::on_open,this,::_1));
	_server.set_close_handler(bind(&Socket::on_close,this,::_1));
	_server.set_message_handler(bind(&Socket::on_message,this,::_1,::_2));

	// Disable logs
	_server.clear_access_channels(websocketpp::log::alevel::frame_header | websocketpp::log::alevel::frame_payload);
	_server.clear_access_channels(websocketpp::log::alevel::all);
}

void Socket::on_open (websocketpp::connection_hdl hdl) {
	_is_alive = true;
	_connections.insert(hdl);
	std::cout << "New socket connection" << '\n';
}

void Socket::on_close (websocketpp::connection_hdl hdl) {
	_connections.erase(hdl);
	std::cout << "Socket connection closed" << '\n';
}

void Socket::on_message (websocketpp::connection_hdl hdl, WsServer::message_ptr msg) {
	// When a new message comes, its content is pushed to the queue
	std::string instruction = msg->get_payload();
	std::pair <websocketpp::connection_hdl, std::string> instructions;
	instructions = std::make_pair(hdl, instruction);
	// send(instructions);
	_client_queue.push(instructions);
}

void Socket::send (std::pair <websocketpp::connection_hdl, std::string> instructions) {
	// Loop through all connexions to send the command
	// con_list::iterator it;
	// for (it = _connections.begin(); it != _connections.end(); ++it) {
	// }
	_server.send(instructions.first, instructions.second, websocketpp::frame::opcode::text);
}

void Socket::run () {
	_server.listen(SOCKET_PORT);
	_server.start_accept();

	std::cout << "Socket server running on port " << SOCKET_PORT << "..." << '\n';
	_server_thread = new std::thread(&WsServer::run, &_server);
}

Socket::~Socket () {
	if (_server_thread->joinable()) {
		_server_thread->join();
	}
}
