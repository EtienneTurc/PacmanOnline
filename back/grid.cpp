#include <stdio.h>

int** grid() {

	width = 28;
	height = 28;
	int row;
	int col;

	int** grid;
	grid = malloc(sizeof(int*) * width);
	if (grid == NULL) exit(-1);
	for (row = 0; row < width; row++) {
		grid[row] = malloc(sizeof(int) * height);
		if (grid[row] == NULL) exit(-1);
	}

	for (row = 0; row < width; row++) {
		for (col = 0; col < height; col++) {
			grid[row][col] = 1;
		}
	}

	// Wall up and down
	for (col = 0; col < height; col++) {
		grid[0][col] = -1;
		grid[width-1][col] = -1;
	}

	// Block 1
	block(grid, 1, 5, width/2, width/2 + 1);

	// Block 2
	block(grid, 2, 4, 2, 5);

	// Block 3
	block(grid, 2, 4, 7, 11);

	// Block 4
	block(grid, 2, 4, width - 12, width - 8);

	// Block 5
	block(grid, 2, 4, width - 6, width - 3);

	// Block 6
	block(grid, 6, 7, 2, 5);

	// Block 7
	block(grid, 6, 7, width - 6, widht - 3);

	// Block 8
	block(grid, 6, 7, 11, width - 12);
	block(grid, 7, 11, width/2, width/2 + 1);

	// Block 9
	block(grid, 6, 13, 7, 8);
	block(grid, 9, 10, 8, 11);

	// Block 10
	block(grid, 6, 13, width - 9, width - 8);
	block(grid, 9, 10, width - 12, width - 9);

	// Block 11
	block(grid, 9, 13, 0, 5);

	// Block 12
	block(grid, 9, 13, width - 6,width - 1);

	// Block 13
	block(grid, height - 14, height- 10, 0, 5);

	// Block 14
	block(grid, height - 14, height- 10, width - 6,width - 1);

	// Block 15
	block(grid, 8, height - 9, 11, width - 12);
	block(grid, 9, height - 10, 12, width - 13);

	// Block 16
	block(grid, height - 14, height- 10, 7, 8);

	// Block 17
	block(grid, height - 14, height- 10, width -9, width - 8);

	// Block 18
	block(grid, height - 12, height - 11, 11, width - 12);
	block(grid, height - 11, height - 9, width/2, width/2 + 1);

	// Block 19
	block(grid, height - 7, height - 6, 11, width - 12);
	block(grid, height - 5, height - 3, width/2, width/2 + 1);
}

void block(int** grid, int row_start, int row_end, int column_start, int column_end) {
	int col;
	int r;
	for (col = column_start; col < column_end + 1; col++) {
		grid[row_start][col] = -1;
		grid[row_end][col] = -1;
	}
	for (r = row_start; r < row_end + 1; r++) {
		grid[r][column_start] = -1;
		grid[r][column_end] = -1;
	}
}
