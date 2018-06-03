function drawGhost(context, quantum, ghost, ghostIndex, isMoving) {
	var isDead = false;
	var isWeak = false;
	var isBlinking = false;

	var xPos = ghost.x_position * quantum + quantum/2;
	var yPos = ghost.y_position * quantum + quantum/2;
	var ghost_radius = quantum/2

	var color
	var RED = "red";
	var PINK = "#ff9cce";
	var CYAN = "#00ffde";
	var ORANGE = "#ffb847";
	var WEAK_COLOR = "#0031ff";
	var BLINKING_COLOR = "white";

	switch (ghostIndex) {
		case 0:
			color = ORANGE
			break;
		case 1:
			color = RED
			break;
		case 2:
			color = CYAN
			break;
		case 3:
			color = PINK
			break;
		default:
			color = "green"
			break;
	}

	// directions
	var UP = 1;
	var LEFT = 2;
	var DOWN = 3;
	var RIGHT = 4;
	var direction = ghost.direction

	if(!isDead){
		// body color
		if(isWeak){
			if(isBlinking){
				context.fillStyle = BLINKING_COLOR;
			}
			else{
				context.fillStyle = WEAK_COLOR;
			}
		}
		else{
			context.fillStyle = color;
		}

		context.beginPath();

		context.arc(xPos, yPos, ghost_radius, Math.PI, 0, false);
		context.moveTo(xPos-ghost_radius, yPos);


		// LEGS
		if (!isMoving){
			context.lineTo(xPos-ghost_radius, yPos+ghost_radius);
			context.lineTo(xPos-ghost_radius+ghost_radius/3, yPos+ghost_radius-ghost_radius/4);
			context.lineTo(xPos-ghost_radius+ghost_radius/3*2, yPos+ghost_radius);
			context.lineTo(xPos, yPos+ghost_radius-ghost_radius/4);
			context.lineTo(xPos+ghost_radius/3, yPos+ghost_radius);
			context.lineTo(xPos+ghost_radius/3*2, yPos+ghost_radius-ghost_radius/4);

			context.lineTo(xPos+ghost_radius, yPos+ghost_radius);
			context.lineTo(xPos+ghost_radius, yPos);
		}
		else {
			context.lineTo(xPos-ghost_radius, yPos+ghost_radius-ghost_radius/4);
			context.lineTo(xPos-ghost_radius+ghost_radius/3, yPos+ghost_radius);
			context.lineTo(xPos-ghost_radius+ghost_radius/3*2, yPos+ghost_radius-ghost_radius/4);
			context.lineTo(xPos, yPos+ghost_radius);
			context.lineTo(xPos+ghost_radius/3, yPos+ghost_radius-ghost_radius/4);
			context.lineTo(xPos+ghost_radius/3*2, yPos+ghost_radius);
			context.lineTo(xPos+ghost_radius, yPos+ghost_radius-ghost_radius/4);
			context.lineTo(xPos+ghost_radius, yPos);
		}


		context.fill();
	}


	if(isWeak){

		if(isBlinking){
			context.fillStyle = "#f00";
			context.strokeStyle = "f00";
		}
		else{
			context.fillStyle = "white";
			context.strokeStyle = "white";
		}

		//eyes
		context.beginPath();//left eye
		context.arc(xPos-ghost_radius/2.5, yPos-ghost_radius/5, ghost_radius/5, 0, Math.PI*2, true); // white
		context.fill();

		context.beginPath(); // right eye
		context.arc(xPos+ghost_radius/2.5, yPos-ghost_radius/5, ghost_radius/5, 0, Math.PI*2, true); // white
		context.fill();

		//mouth
		context.beginPath();
		context.lineWidth=1;
		context.moveTo(xPos-ghost_radius+ghost_radius/5, yPos+ghost_radius/2);
		context.lineTo(xPos-ghost_radius+ghost_radius/3, yPos+ghost_radius/4);
		context.lineTo(xPos-ghost_radius+ghost_radius/3*2, yPos+ghost_radius/2);
		context.lineTo(xPos, yPos+ghost_radius/4);
		context.lineTo(xPos+ghost_radius/3, yPos+ghost_radius/2);
		context.lineTo(xPos+ghost_radius/3*2, yPos+ghost_radius/4);
		context.lineTo(xPos+ghost_radius-ghost_radius/5, yPos+ghost_radius/2);
		context.stroke();
	}
	else{
		// EYES
		context.fillStyle = "white"; //left eye
		context.beginPath();
		context.arc(xPos-ghost_radius/2.5, yPos-ghost_radius/5, ghost_radius/3, 0, Math.PI*2, true); // white
		context.fill();

		context.fillStyle = "white"; //right eye
		context.beginPath();
		context.arc(xPos+ghost_radius/2.5, yPos-ghost_radius/5, ghost_radius/3, 0, Math.PI*2, true); // white
		context.fill();


		switch(direction){

			case UP:
			context.fillStyle="black"; //left eyeball
			context.beginPath();
			context.arc(xPos-ghost_radius/3, yPos-ghost_radius/5-ghost_radius/6, ghost_radius/6, 0, Math.PI*2, true); //black
			context.fill();

			context.fillStyle="black"; //right eyeball
			context.beginPath();
			context.arc(xPos+ghost_radius/3, yPos-ghost_radius/5-ghost_radius/6, ghost_radius/6, 0, Math.PI*2, true); //black
			context.fill();
			break;

			case DOWN:
			context.fillStyle="black"; //left eyeball
			context.beginPath();
			context.arc(xPos-ghost_radius/3, yPos-ghost_radius/5+ghost_radius/6, ghost_radius/6, 0, Math.PI*2, true); //black
			context.fill();

			context.fillStyle="black"; //right eyeball
			context.beginPath();
			context.arc(xPos+ghost_radius/3, yPos-ghost_radius/5+ghost_radius/6, ghost_radius/6, 0, Math.PI*2, true); //black
			context.fill();
			break;

			case LEFT:
			context.fillStyle="black"; //left eyeball
			context.beginPath();
			context.arc(xPos-ghost_radius/3-ghost_radius/5, yPos-ghost_radius/5, ghost_radius/6, 0, Math.PI*2, true); //black
			context.fill();

			context.fillStyle="black"; //right eyeball
			context.beginPath();
			context.arc(xPos+ghost_radius/3-ghost_radius/15, yPos-ghost_radius/5, ghost_radius/6, 0, Math.PI*2, true); //black
			context.fill();
			break;

			case RIGHT:
			context.fillStyle="black"; //left eyeball
			context.beginPath();
			context.arc(xPos-ghost_radius/3+ghost_radius/15, yPos-ghost_radius/5, ghost_radius/6, 0, Math.PI*2, true); //black
			context.fill();

			context.fillStyle="black"; //right eyeball
			context.beginPath();
			context.arc(xPos+ghost_radius/3+ghost_radius/5, yPos-ghost_radius/5, ghost_radius/6, 0, Math.PI*2, true); //black
			context.fill();
			break;

		}

	}
}
