window.onload = function () {
	var canvas = document.getElementById('canvas');
	if (!canvas) {
		alert("Impossible to get the canvas");
		return;
	}

	var context = canvas.getContext('2d');
	if (!context) {
		alert("Impossible to get the canvas context");
		return;
	}

	var myInterval = setInterval(animate, 1000 / 30);

	var xPos = 10
	var yPos = 10

	function animate() {
		context.fillRect(xPos, yPos, 100, 100);
		context.fillRect(200, 200, 100, 100);
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
