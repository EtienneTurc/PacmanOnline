function drawPacman(context) {

	var xPos = 150;
	var yPos = 150;
	var pacman_radius = 9

	var PACMAN_COLOR = "yellow"
	var color;
	var mouthOpen = true

	// directions
	var UP = 1;
	var DOWN = 2;
	var LEFT = 3;
	var RIGHT = 4;
	var direction = LEFT

	if (color == undefined){
		context.fillStyle = PACMAN_COLOR;
	}
	else{
		context.fillStyle = color;
	}
	context.beginPath();

	if (!mouthOpen){
		switch(direction){
			case UP:
			context.arc(xPos, yPos, pacman_radius, 2*Math.PI-Math.PI*11/18, 2*Math.PI-Math.PI*7/18, true);
			break;

			case DOWN:
			context.arc(xPos, yPos, pacman_radius, 2*Math.PI-Math.PI*29/18, 2*Math.PI-Math.PI*25/18, true);
			break;

			case LEFT:
			context.arc(xPos, yPos, pacman_radius, 2*Math.PI-Math.PI*10/9, 2*Math.PI-Math.PI*8/9, true);
			break;

			case RIGHT:
			context.arc(xPos, yPos, pacman_radius, 2*Math.PI-Math.PI/9, 2*Math.PI-Math.PI*17/9, true);
			break;

			default:
			break;
		}
	}
	else {
		switch(direction){
			case UP:
			context.arc(xPos, yPos, pacman_radius, 2*Math.PI-Math.PI*7/9, 2*Math.PI-Math.PI*2/9, true);
			break;

			case DOWN:
			context.arc(xPos, yPos, pacman_radius, 2*Math.PI-Math.PI*16/9, 2*Math.PI-Math.PI*11/9, true);
			break;

			case LEFT:
			context.arc(xPos, yPos, pacman_radius, 2*Math.PI-Math.PI*23/18, 2*Math.PI-Math.PI*13/18, true);
			break;

			case RIGHT:
			context.arc(xPos, yPos, pacman_radius, 2*Math.PI-Math.PI*5/18, 2*Math.PI-Math.PI*31/18, true);
			break;

			default:
			break;

		}
	}




	context.lineTo(xPos, yPos);
	context.fill();
}
