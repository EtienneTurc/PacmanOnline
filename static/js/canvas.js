var quantum
var pacmanMouth
var ghostOndulation
var blinking

function init() {
	pacmanMouth = false;
	ghostOndulation = false;
	blinking = false;
}

function game() {
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

	if (canvas.width/28 < canvas.height/36) {
		quantum = Math.floor(canvas.width/28)
	} else {
		quantum = Math.floor(canvas.height/36)
	}

	animate()

	function animate() {
		context.fillStyle = "black";
		context.fillRect(0, 0, canvas.width, canvas.height);

		pacmanMouth = !pacmanMouth;
		ghostOndulation = !ghostOndulation;
		if (next_attack_in <= 7) {
			blinking = !blinking
		} else {
			blinking = false
		}

		drawGrid(context, quantum)

		for (var i = 0; i < pacmans.length; i++) {
			drawPacman(context, quantum, pacmans[i], pacmanMouth)
		}
		for (var i = 0; i < ghosts.length; i++) {
			drawGhost(context, quantum, ghosts[i], i, ghostOndulation, blinking)
		}
	}
}
