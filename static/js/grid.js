function drawGrid (context, quantum) {


	var BORDER_COLOR = "white"
	var WALL_COLOR = "black"
	var PATH_COLOR = "grey"
	var SMALL_BALL_COLOR = "yellow"

	var SMALL_BALL_RADIUS = 2

	var sizeX = 28
	var sizeY = 36

	var grid = [
		[0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
		[0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
		[0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
		[0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
		[0, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 0, 0, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 0],
		[0, 2, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 2, 0, 0, 2, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 2, 0],
		[0, 2, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 2, 0, 0, 2, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 2, 0],
		[0, 2, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 2, 0, 0, 2, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 2, 0],
		[0, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 0],
		[0, 2, 0, 0, 0, 0, 2, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 2, 0, 0, 0, 0, 2, 0],
		[0, 2, 0, 0, 0, 0, 2, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 2, 0, 0, 0, 0, 2, 0],
		[0, 2, 2, 2, 2, 2, 2, 0, 0, 2, 2, 2, 2, 0, 0, 2, 2, 2, 2, 0, 0, 2, 2, 2, 2, 2, 2, 0],
		[0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 2, 0, 0, 2, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0],
		[0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 2, 0, 0, 2, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0],
		[0, 0, 0, 0, 0, 0, 2, 0, 0, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 0, 0, 2, 0, 0, 0, 0, 0, 0],
		[0, 0, 0, 0, 0, 0, 2, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 2, 0, 0, 0, 0, 0, 0],
		[0, 0, 0, 0, 0, 0, 2, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 2, 0, 0, 0, 0, 0, 0],
		[2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 0, 0, 0, 0, 0, 0, 0, 0, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2],
		[0, 0, 0, 0, 0, 0, 2, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 2, 0, 0, 0, 0, 0, 0],
		[0, 0, 0, 0, 0, 0, 2, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 2, 0, 0, 0, 0, 0, 0],
		[0, 0, 0, 0, 0, 0, 2, 0, 0, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 0, 0, 2, 0, 0, 0, 0, 0, 0],
		[0, 0, 0, 0, 0, 0, 2, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 2, 0, 0, 0, 0, 0, 0],
		[0, 0, 0, 0, 0, 0, 2, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 2, 0, 0, 0, 0, 0, 0],
		[0, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 0, 0, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 0],
		[0, 2, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 2, 0, 0, 2, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 2, 0],
		[0, 2, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 2, 0, 0, 2, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 2, 0],
		[0, 2, 2, 2, 0, 0, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 0, 0, 2, 2, 2, 0],
		[0, 0, 0, 2, 0, 0, 2, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 2, 0, 0, 2, 0, 0, 0],
		[0, 0, 0, 2, 0, 0, 2, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 2, 0, 0, 2, 0, 0, 0],
		[0, 2, 2, 2, 2, 2, 2, 0, 0, 2, 2, 2, 2, 0, 0, 2, 2, 2, 2, 0, 0, 2, 2, 2, 2, 2, 2, 0],
		[0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0],
		[0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0],
		[0, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 0],
		[0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
		[0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
		[0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0]
	]

	for (var i = 0; i < grid.length; i++) {
		for (var j = 0; j < grid[0].length; j++) {

			//Fill in color the path and walls
			if (grid[i][j] == 0) {
				context.fillStyle = WALL_COLOR
				context.fillRect(j*quantum, i*quantum, (j+1)* quantum, (i+1)*quantum)

				context.beginPath()
				var im = i - 1;
				if (i == 0) {
					im = sizeX - 1;
				}
				var jm = j-1;
				if (j == 0) {
					jm = sizeY - 1;
				}
				
				if (grid[im][j] != 0) {
					// bottom line
					if (grid[i][(j-1)%sizeY] != 0) {
						//toward bottom left
						context.arc((j+1)*quantum , (i+1)*quantum, quantum/2, 0*Math.PI, 1.5*Math.PI);
					} else if (grid[i][(j+1)%sizeY] != 0) {
						//toward bottom right
						context.arc(j*quantum , (i+1)*quantum, quantum/2, 1.5*Math.PI, 2*Math.PI);
					}
					else {
						context.moveTo(j*quantum, (i+0.5)*quantum);
						context.lineTo((j+1)*quantum, (i+0.5)*quantum);
					}
				} else if (grid[(i+1)%sizeX][j] != 0) {
					//top line
					if (grid[i][(j+1)%sizeY] != 0) {
						//PB
						// context.arc(((j+1)%sizeX)*quantum , ((i+1)%sizeY)*quantum, quantum/2, 1.5*Math.PI, 2*Math.PI);
					}
					//bottom left corner
					else if (grid[i][(j-1)%sizeY] != 0) {
						//toward to left
						context.arc((j+1)*quantum , i*quantum, quantum/2, 0*Math.PI, 1*Math.PI);

					}
					//simple path left
					else {
						context.moveTo(j*quantum, (i+0.5)*quantum);
						context.lineTo((j+1)*quantum, (i+0.5)*quantum);
					}
				} else if (grid[i][jm] != 0) {
					//right line
					if (grid[(i+1)%sizeX][j] != 0) {
						//PB
						// context.arc((j+1)*quantum , (i+1)*quantum, quantum/2, 0*Math.PI, 1.5*Math.PI);
					} else if (grid[im][j] != 0) {
						//PB
						// context.arc(j*quantum , (i+1)*quantum, quantum/2, 0*Math.PI, 1.5*Math.PI);
					}
					else {
						context.moveTo((j+0.5)*quantum, i*quantum);
						context.lineTo((j+0.5)*quantum, (i+1)*quantum);
					}
				} else if (grid[i][(j+1)%sizeY]) {
					//left line
					if (grid[(i+1)%sizeX][j] != 0) {
						//PB
						// context.arc((j+1)*quantum , (i+1)*quantum, quantum/2, 0*Math.PI, 1.5*Math.PI);
					} else if (grid[im][j] != 0) {
						//PB
						// context.arc(j*quantum , (i+1)*quantum, quantum/2, 0*Math.PI, 1.5*Math.PI);
					}
					else {
						context.moveTo((j+0.5)*quantum, i*quantum);
						context.lineTo((j+0.5)*quantum, (i+1)*quantum);
					}
				}

				context.lineWidth = 5;
				context.strokeStyle = "red";
				context.stroke();
				context.closePath()



			} else {
				context.fillStyle = PATH_COLOR
				context.fillRect(j*quantum, i*quantum, (j+1)* quantum, (i+1)*quantum)
			}

			//draw the smal balls
			if (grid[i][j] == 2) {
				context.beginPath();
		        context.fillStyle = SMALL_BALL_COLOR;
				context.arc((j+0.5)*quantum , (i+0.5)*quantum, SMALL_BALL_RADIUS, 0*Math.PI, 2*Math.PI);
		        context.fill();
		        // context.lineWidth = 5;
		        // context.strokeStyle = '#003300';
				context.closePath()
			}
			// drawExternalBorder(context, quantum, grid, i, j)

		}
	}

}

function drawExternalBorder(context, quantum, grid, i, j) {



	context.beginPath();
	if (grid[(i-1)%sizeX][j] != 0) {
		//bottom right corner
		if (grid[i][(j-1)%sizeY] != 0) {
			context.arc(j*quantum , i*quantum, quantum/2, 0.5*Math.PI, 0*Math.PI);

		}
		//top right corner
		else if (grid[i][(j+1)%sizeY] != 0) {
			context.arc((j+1)*quantum , i*quantum, quantum/2, 0*Math.PI, 1.5*Math.PI);

		}
		//simple path right
		else {
			context.moveTo((j+0.5)*quantum, i*quantum);
			context.lineTo((j+0.5)*quantum, (i+0.5)*quantum);
		}
	} else if (grid[(i+1)%sizeX][j] != 0) {
		//top left corner
		if (grid[i][(j+1)%sizeY] != 0) {
			context.arc((j+1)*quantum , (i+1)*quantum, quantum/2, 1.5*Math.PI, 2*Math.PI);

		}
		//bottom left corner
		else if (grid[i][(j-1)%sizeY] != 0) {
			context.arc(j*quantum , (i+1)*quantum, quantum/2, 0*Math.PI, 1.5*Math.PI);

		}
		//simple path left
		else {
			context.moveTo((j+0.5)*quantum, i*quantum);
			context.lineTo((j+0.5)*quantum, (i+0.5)*quantum);
		}
	}
	context.lineWidth = 5;
	context.strokeStyle = "red";
	context.stroke();
	context.closePath()
}
