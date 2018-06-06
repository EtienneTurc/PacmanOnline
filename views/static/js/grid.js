function mod(n, m) {
	return ((n % m) + m) % m;
}

function drawGrid (context, quantum) {

	var BORDER_COLOR = "#0047cc"
	var WALL_COLOR = "black"
	var PATH_COLOR = "grey"
	var SMALL_BALL_COLOR = "#fbf2b7"
	var BIG_BALL_COLOR = "#F6DC12"

	var SMALL_BALL_RADIUS = 2
	var BIG_BALL_RADIUS = 4

	for (var i = 0; i < sizeX; i++) {
		for (var j = 0; j < sizeY; j++) {
			context.beginPath()

			//Fill in color the path and walls
			if (grid[i][j] == 0) {
				if (grid[mod(i-1,sizeX)][mod(j,sizeY)] != 0 && grid[mod(i,sizeX)][mod(j-1,sizeY)] !=0 ) {
					context.arc((i+1)*quantum,(j+1)*quantum, quantum/2, Math.PI, 1.5*Math.PI);
				} else if (grid[mod(i+1,sizeX)][mod(j,sizeY)] != 0 && grid[mod(i,sizeX)][mod(j-1,sizeY)] !=0) {
					context.arc(i*quantum,(j+1)*quantum, quantum/2, 1.5*Math.PI, 2*Math.PI);
				} else if (grid[mod(i+1,sizeX)][mod(j,sizeY)] != 0 && grid[mod(i,sizeX)][mod(j+1,sizeY)] !=0) {
					context.arc(i*quantum,j*quantum, quantum/2, 0, 0.5*Math.PI);
				} else if (grid[mod(i-1,sizeX)][mod(j,sizeY)] != 0 && grid[mod(i,sizeX)][mod(j+1,sizeY)] !=0) {
					context.arc((i+1)*quantum,j*quantum, quantum/2, 0.5*Math.PI, Math.PI);
				} else if (grid[mod(i-1,sizeX)][mod(j,sizeY)] != 0 || grid[mod(i+1,sizeX)][mod(j,sizeY)] != 0) {
					context.moveTo((i+0.5)*quantum, j*quantum);
					context.lineTo((i+0.5)*quantum, (j+1)*quantum);
				} else if (grid[mod(i,sizeX)][mod(j-1,sizeY)] != 0 || grid[mod(i,sizeX)][mod(j+1,sizeY)] != 0) {
					context.moveTo(i*quantum, (j+0.5)*quantum);
					context.lineTo((i+1)*quantum, (j+0.5)*quantum);
				} else if (grid[mod((i-1),sizeX)][mod(j-1,sizeY)] != 0) {
					context.arc(i*quantum,j*quantum, quantum/2, 0, 0.5*Math.PI);
				} else if (grid[mod((i+1),sizeX)][mod(j-1,sizeY)] != 0) {
					context.arc((i+1)*quantum,j*quantum, quantum/2, 0.5*Math.PI, Math.PI);
				} else if (grid[mod((i+1),sizeX)][mod(j+1,sizeY)] != 0) {
					context.arc((i+1)*quantum,(j+1)*quantum, quantum/2, Math.PI, 1.5*Math.PI);
				} else if (grid[mod((i-1),sizeX)][mod(j+1,sizeY)] != 0) {
					context.arc(i*quantum,(j+1)*quantum, quantum/2, 1.5*Math.PI, 2*Math.PI);
				}

				context.lineWidth = 5;
				context.strokeStyle = BORDER_COLOR;
				context.stroke();
				context.closePath()
			}
			//draw the smal balls
			if (grid[i][j] == 2) {
				context.beginPath();
				context.fillStyle = SMALL_BALL_COLOR;
				context.arc((i+0.5)*quantum, (j+0.5)*quantum, SMALL_BALL_RADIUS, 0*Math.PI, 2*Math.PI);
				context.fill();
				context.closePath()
			} else if (grid[i][j] == 3) {
				context.beginPath();
				context.fillStyle = BIG_BALL_COLOR;
				context.arc((i+0.5)*quantum, (j+0.5)*quantum, BIG_BALL_RADIUS, 0*Math.PI, 2*Math.PI);
				context.fill();
				context.closePath()
			}
		}
	}
}
