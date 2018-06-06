#ifndef SOCKET_H
#define SOCKET_H

#include "safequeue.h"
#include <set>
#include <websocketpp/config/asio_no_tls.hpp>
#include <websocketpp/server.hpp>

typedef websocketpp::server<websocketpp::config::asio> WsServer;
typedef std::set<websocketpp::connection_hdl,std::owner_less<websocketpp::connection_hdl> > con_list;

using websocketpp::lib::placeholders::_1;
using websocketpp::lib::placeholders::_2;
using websocketpp::lib::bind;

class Socket {
private:
	WsServer _server;
	con_list _connections;
	std::thread* _server_thread;
	SafeQueue<std::pair <websocketpp::connection_hdl, std::string>> _client_queue;
	SafeQueue<websocketpp::connection_hdl> _closed_connections;
	bool _is_alive;
	void* _handler_queue;

	// Callbacks
	void on_open (websocketpp::connection_hdl);
	void on_close (websocketpp::connection_hdl);
	void on_message (websocketpp::connection_hdl hdl, WsServer::message_ptr);

public:
	void run ();
	bool isAlive () { return _is_alive; }
	void send (std::pair <websocketpp::connection_hdl, std::string> instructions);
	SafeQueue<std::pair <websocketpp::connection_hdl, std::string>>* getQueuePtr() {
		return &_client_queue;
	}
	SafeQueue<websocketpp::connection_hdl>* getClosedConnectionsPtr() {
		return &_closed_connections;
	}

	Socket ();
	~Socket ();
};

#endif
