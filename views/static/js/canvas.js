var quantum
var pacmanMouth
var ghostOndulation
var blinking
var iteration

window.onload=function(){
	document.getElementById("button").style.display='none';

}

function showButton(){
	if (count === 0) {
		document.getElementById("button").style.display='block';
	}
}

// Function that init the graphics of the game
function init() {
	pacmanMouth = false;
	ghostOndulation = false;
	blinking = false;
	iteration = 0;
	count = 3;
}

// Function that draws the game
function game() {
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

	context.canvas.width = window.innerWidth
	context.canvas.height = window.innerHeight

	if (canvas.width/28 < canvas.height/36) {
		quantum = Math.floor(canvas.width/28)
		context.canvas.height = quantum * 36
	} else {
		quantum = Math.floor(canvas.height/36)
		context.canvas.width = quantum * 28
	}

	if (count === 0) {
		animate()
		showButton()
		if (game_over) {
			gameOver()
		}
		if (has_won) {
			hasWon()
		}
	} else {
		countDown(count)
	}

	// Function that draws the grid, pacman and the ghosts
	function animate() {
		context.fillStyle = "black";
		context.fillRect(0, 0, canvas.width, canvas.height);

		if (iteration%2 == 1) {
			pacmanMouth = !pacmanMouth;
			ghostOndulation = !ghostOndulation;
			if (next_attack_in <= 30) {
				blinking = !blinking
			} else {
				blinking = false
			}
		}
		iteration++

		drawGrid(context, quantum)

		for (var i = 0; i < pacmans.length; i++) {
			drawPacman(context, quantum, pacmans[i], pacmanMouth)
		}
		for (var i = 0; i < ghosts.length; i++) {
			drawGhost(context, quantum, ghosts[i], i, ghostOndulation, blinking)
		}

		context.font = quantum + "px Bangers, cursive";
		context.fillStyle = "#F9C328";
		context.textAlign="center";
		context.fillText("Score : " + pacmans[0].score,context.canvas.width/2,context.canvas.height - 1.2*quantum);

	}

	// Function that draws game Over with the score
	function gameOver() {
		context.fillStyle = "#F9C328";
		context.textAlign="center";
		context.shadowOffsetX = quantum/5
		context.shadowOffsetY = quantum/5
		context.shadowColor = "black"
		context.shadowBlur = quantum/5
		context.font = 2*quantum + "px Bangers, cursive";
		context.fillText("You scored " + pacmans[0].score + " points.",context.canvas.width/2,context.canvas.height/2 + 2.5*quantum);
		context.font = "bold " + 3.5*quantum + "px Bangers, cursive";
		context.fillText("GAME OVER ",context.canvas.width/2, context.canvas.height/2 - 3*quantum);
	}

	// Function that draws Has Won with the score
	function hasWon() {
		context.fillStyle = "#F9C328";
		context.textAlign="center";
		context.shadowOffsetX = quantum/5
		context.shadowOffsetY = quantum/5
		context.shadowColor = "black"
		context.shadowBlur = quantum/5
		context.font = 2*quantum + "px Bangers, cursive";
		context.fillText("You scored " + pacmans[0].score + " points.",context.canvas.width/2,context.canvas.height/2 + 2.5*quantum);
		context.font = "bold " + 3.5*quantum + "px Bangers, cursive";
		context.fillText("YOU WON !! ",context.canvas.width/2, context.canvas.height/2 - 3*quantum);
	}

	// Function that draws the count down
	function countDown(){
		context.fillStyle = "black";
		context.fillRect(0, 0, canvas.width, canvas.height);
		context.fillStyle = "#F9C328";
		context.textAlign="center";
		// context.shadowOffsetX = quantum/5
		// context.shadowOffsetY = quantum/5
		// context.shadowColor = "black"
		// context.shadowBlur = quantum/5
		context.font = 6*quantum + "px Bangers, cursive";
		context.fillText(count, context.canvas.width/2, context.canvas.height/2);

	}
}
