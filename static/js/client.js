const socket = new WebSocket('ws://localhost:8080');
var grid = []
var pacmans = []
var ghosts = []
var next_attack_in
var sizeX
var sizeY

socket.addEventListener('open', function (event) {
	socket.send("routeBeginGame;1;2;");
});

socket.addEventListener('message', function (event) {
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
	sizeX = data[0]
	sizeY = data[1]
	for (var i = 0; i < sizeY; i++) {
		grid.push(new Array(sizeX))
	}
	data.splice(0,2)
	for (var i = 0; i < sizeY; i++) {
		for (var j = 0; j < sizeY; j++) {
			grid[i][j] = parseInt(data[j*sizeY + i])
		}
	}
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
