const socket = new WebSocket('ws://localhost:8080');

socket.addEventListener('open', function (event) {
	socket.send("routeBeginGame;1;2;");
});
