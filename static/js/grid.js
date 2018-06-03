function drawGrid (context, quantum) {


	var BORDER_COLOR = "white"
	var WALL_COLOR = "black"
	var PATH_COLOR = "grey"
	var SMALL_BALL_COLOR = "yellow"
	var BIG_BALL_COLOR = "orange"

	var SMALL_BALL_RADIUS = 2
	var BIG_BALL_RADIUS = 4

	// var sizeX = 28
	// var sizeY = 36
    //
	// var grid = [
	// 	[0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
	// 	[0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
	// 	[0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
	// 	[0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
	// 	[0, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 0, 0, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 0],
	// 	[0, 2, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 2, 0, 0, 2, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 2, 0],
	// 	[0, 2, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 2, 0, 0, 2, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 2, 0],
	// 	[0, 2, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 2, 0, 0, 2, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 2, 0],
	// 	[0, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 0],
	// 	[0, 2, 0, 0, 0, 0, 2, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 2, 0, 0, 0, 0, 2, 0],
	// 	[0, 2, 0, 0, 0, 0, 2, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 2, 0, 0, 0, 0, 2, 0],
	// 	[0, 2, 2, 2, 2, 2, 2, 0, 0, 2, 2, 2, 2, 0, 0, 2, 2, 2, 2, 0, 0, 2, 2, 2, 2, 2, 2, 0],
	// 	[0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 2, 0, 0, 2, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0],
	// 	[0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 2, 0, 0, 2, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0],
	// 	[0, 0, 0, 0, 0, 0, 2, 0, 0, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 0, 0, 2, 0, 0, 0, 0, 0, 0],
	// 	[0, 0, 0, 0, 0, 0, 2, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 2, 0, 0, 0, 0, 0, 0],
	// 	[0, 0, 0, 0, 0, 0, 2, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 2, 0, 0, 0, 0, 0, 0],
	// 	[2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 0, 0, 0, 0, 0, 0, 0, 0, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2],
	// 	[0, 0, 0, 0, 0, 0, 2, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 2, 0, 0, 0, 0, 0, 0],
	// 	[0, 0, 0, 0, 0, 0, 2, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 2, 0, 0, 0, 0, 0, 0],
	// 	[0, 0, 0, 0, 0, 0, 2, 0, 0, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 0, 0, 2, 0, 0, 0, 0, 0, 0],
	// 	[0, 0, 0, 0, 0, 0, 2, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 2, 0, 0, 0, 0, 0, 0],
	// 	[0, 0, 0, 0, 0, 0, 2, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 2, 0, 0, 0, 0, 0, 0],
	// 	[0, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 0, 0, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 0],
	// 	[0, 2, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 2, 0, 0, 2, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 2, 0],
	// 	[0, 2, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 2, 0, 0, 2, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 2, 0],
	// 	[0, 2, 2, 2, 0, 0, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 0, 0, 2, 2, 2, 0],
	// 	[0, 0, 0, 2, 0, 0, 2, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 2, 0, 0, 2, 0, 0, 0],
	// 	[0, 0, 0, 2, 0, 0, 2, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 2, 0, 0, 2, 0, 0, 0],
	// 	[0, 2, 2, 2, 2, 2, 2, 0, 0, 2, 2, 2, 2, 0, 0, 2, 2, 2, 2, 0, 0, 2, 2, 2, 2, 2, 2, 0],
	// 	[0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0],
	// 	[0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0],
	// 	[0, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 0],
	// 	[0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
	// 	[0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
	// 	[0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0]
	// ]

	for (var i = 0; i < grid.length; i++) {
		for (var j = 0; j < grid[0].length; j++) {
			context.fillStyle = WALL_COLOR
			context.fillRect(j*quantum, i*quantum, (j+1)* quantum, (i+1)*quantum)

			//Fill in color the path and walls
			if (grid[i][j] == 0) {

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
					if (grid[i][jm] != 0) {
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
						//toward up right
						context.arc((j%sizeX)*quantum , (i%sizeY)*quantum, quantum/2, 0*Math.PI, 0.5*Math.PI);
					}
					//bottom left corner
					else if (grid[i][jm] != 0) {
						//toward to up left
						context.arc((j+1)*quantum , i*quantum, quantum/2, 0*Math.PI, 1*Math.PI);
					}
					//simple path left
					else {
						context.moveTo(j*quantum, (i+0.5)*quantum);
						context.lineTo((j+1)*quantum, (i+0.5)*quantum);
					}
				} else if (grid[im][jm] != 0 && grid[im][j] == 0 && grid[i][jm]==0) {
					//bottom right angle
					context.arc(j*quantum , i*quantum, quantum/2, 0*Math.PI, 0.5*Math.PI);
				} else if (grid[(i+1)%sizeX][(j+1)%sizeY] != 0 && grid[(i+1)%sizeX][j] == 0 && grid[i][(j+1)%sizeY]==0) {
					//top left angle
					context.arc((j+1)*quantum , (i+1)*quantum, quantum/2, 1*Math.PI, 1.5*Math.PI);
				} else if (grid[im][(j+1)%sizeY] != 0 && grid[im][j] == 0 && grid[i][(j+1)%sizeY]==0) {
					//bottom left angle
					context.arc((j+1)*quantum , i*quantum, quantum/2, 0.5*Math.PI, 1*Math.PI);
				} else if (grid[(i+1)%sizeX][jm] != 0 && grid[(i+1)%sizeX][j] == 0 && grid[i][jm]==0) {
					//top right angle
					context.arc(j*quantum , (i+1)*quantum, quantum/2, 1.5*Math.PI, 2*Math.PI);
				}

				if ((grid[i][jm] != 0) && (grid[(i+1)%sizeX][j] == 0) && (grid[im][j] == 0)){
					//right line
					context.moveTo((j+0.5)*quantum, i*quantum);
					context.lineTo((j+0.5)*quantum, (i+1)*quantum);
				} else if ((grid[i][(j+1)%sizeY]) && (grid[(i+1)%sizeX][j] == 0) && (grid[im][j] == 0)) {
					//left line
					context.moveTo((j+0.5)*quantum, i*quantum);
					context.lineTo((j+0.5)*quantum, (i+1)*quantum);
				}

				context.lineWidth = 5;
				context.strokeStyle = "red";
				context.stroke();
				context.closePath()

			} else {
				// context.fillStyle = PATH_COLOR
				// context.fillRect(j*quantum, i*quantum, (j+1)* quantum, (i+1)*quantum)
			}

			//draw the smal balls
			if (grid[i][j] == 2) {
				context.beginPath();
		        context.fillStyle = SMALL_BALL_COLOR;
				context.arc((j+0.5)*quantum , (i+0.5)*quantum, SMALL_BALL_RADIUS, 0*Math.PI, 2*Math.PI);
		        context.fill();
				context.closePath()
			} else if (grid[i][j] == 3) {
				context.beginPath();
		        context.fillStyle = BIG_BALL_COLOR;
				context.arc((j+0.5)*quantum , (i+0.5)*quantum, BIG_BALL_RADIUS, 0*Math.PI, 2*Math.PI);
		        context.fill();
				context.closePath()
			}
		}
	}
}
