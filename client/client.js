const WebSocket = require('ws');

const ws = new WebSocket('ws://localhost:8080');

ws.on('open', function open() {
	ws.send("Voila un autre message du client");
});

ws.on('message', function incoming(data) {
	console.log('Received message : ',data);
});
