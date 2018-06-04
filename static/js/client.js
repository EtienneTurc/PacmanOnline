const socket = new WebSocket('ws://localhost:8080');
var grid = []
var pacmans = []
var ghosts = []
var next_attack_in
var sizeX
var sizeY
var new_grid = false

socket.addEventListener('open', function (event) {
	init()
	socket.send("routeBeginGame;1;2;");
	console.log(socket.readyState)
});

socket.addEventListener('error', function (error) {
	console.log(error);
	console.log(socket.readyState)
})

socket.onclose = function() {
	console.log(socket.readyState)
	// websocket is closed.
	alert("Connection is closed...");
};

socket.addEventListener('message', function (event) {
	console.log(socket.readyState)
	var data = event.data.split(";")
	var route = data[0]
	data.splice(0,1)

	switch (route) {
		case "routeGetGrid":
		routeGetGrid(data);
		break;
		case "routeGetEntity":
		routeGetEntity(data);
		break;
		case "routeGetNextAttackIn":
		routeGetNextAttackIn(data);
		break;
		default:
		break;
	}
});

function routeGetGrid(data) {
	grid = [[]]
	sizeX = parseInt(data[0])
	sizeY = parseInt(data[1])
	for (var i = 0; i < sizeY; i++) {
		grid.push(new Array(sizeX))
	}
	data.splice(0,2)
	for (var i = 0; i < sizeX; i++) {
		for (var j = 0; j < sizeY; j++) {
			grid[i][j] = parseInt(data[j + i*sizeY])
		}
	}
	game()
}

function routeGetNextAttackIn(data) {
	next_attack_in = parseInt(data[0])
	// console.log(next_attack_in);
}

//Route;Pacman or Ghost?;Index in vector;XPosition;YPosition;Direction;Fraction;Score
function routeGetEntity(data) {
	is_pacman = (data[0] == "true")
	index_in_vector =  parseInt(data[1])
	entity_size = parseInt(data[2])

	let entity = {x_position:parseInt(data[3]), y_position: parseInt(data[4]),direction: parseFloat(data[5]), fraction: parseFloat(data[6]),score: parseInt(data[7]) }

	if (is_pacman) {
		while (pacmans.length < entity_size) {
			pacmans.push({})
		}
		pacmans[index_in_vector] = entity
	} else {
		while (entity.length < entity_size) {
			entity.push({})
		}
		ghosts[index_in_vector] = entity
	}
}

document.onkeydown = function(e) {
	let direction = "0"
	switch (e.keyCode) {
		case 37:
		// left
		direction = "2";
		break;
		case 38:
		// up
		direction = "1";
		break;
		case 39:
		// right
		direction = "4";
		break;
		case 40:
		// down
		direction = "3";
		break;
		default: break;
	}

	if (direction != "0") {
		socket.send("routePostEntityDirection;true;0;"+ direction + ";");
	}
};
