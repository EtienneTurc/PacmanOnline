window.onload = function () {
	var canvas = document.getElementById('canvas');
	// canvas.setAttribute('width', 420);
	// canvas.setAttribute('height', 540);

	if (!canvas) {
		alert("Impossible to get the canvas");
		return;
	}

	var context = canvas.getContext('2d');
	if (!context) {
		alert("Impossible to get the canvas context");
		return;
	}

	context.canvas.width = window.innerWidth
	context.canvas.height = window.innerHeight
	var quantum;

	if (canvas.width/28 < canvas.height/36) {
		quantum = Math.floor(canvas.width/28)
	} else {
		quantum = Math.floor(canvas.height/36)
	}

	// context.fillStyle = "black";
	// context.fillRect(0, 0, canvas.width, canvas.height);

	var myInterval = setInterval(animate, 1000 / 30);


	var xPos = 10
	var yPos = 10


	function animate() {
		// drawGrid(context, quantum)
		// drawGhost(context, true)
		drawPacman(context)
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
