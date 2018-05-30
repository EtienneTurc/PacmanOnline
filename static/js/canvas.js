window.onload = function () {
	var canvas = document.getElementById('canvas');
	canvas.setAttribute('width', 420);
	canvas.setAttribute('height', 540);

	if (!canvas) {
		alert("Impossible to get the canvas");
		return;
	}

	var context = canvas.getContext('2d');
	if (!context) {
		alert("Impossible to get the canvas context");
		return;
	}

	// context.fillStyle = "black";
	// context.fillRect(0, 0, canvas.width, canvas.height);

	var myInterval = setInterval(animate, 1000 / 30);


	var xPos = 10
	var yPos = 10


	function animate() {
		drawGrid(context)
		// context.fillRect(xPos, yPos, 100, 100);
		// context.fillRect(200, 200, 100, 100);
		context.fillStyle = "yellow"
		context.strock()
		// context.arc(150 , 150, 50, 0*Math.PI, 2*Math.PI, true);
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
		console.log("routePostEntityDirection;true;0;"+ direction + ";");
	}
};



















// document.addEventListener('keydown', (event) => {const keyName = event.key;
// 	let direction = "0"
// 	console.log(keyName);
// 	switch (keyName) {
// 		// Up
// 		case 38:
// 		direction = "1";
// 		break;
// 		// Left
// 		case 37:
// 		direction = "2";
// 		break;
// 		// Down
// 		case 40:
// 		direction = "3";
// 		break;
// 		// Right
// 		case 39:
// 		direction = "4";
// 		break;
// 		default:
// 		break;
// 	}
//
// });
