#include "grid.h"
#include <iostream>
#include <vector>
#include "raylib.h"
#include "colors.h"

Grid::Grid() {
	numrows = 20;
	numcols = 10;
	cellsize = 30;
	initialize();
	colors = getcellcolors();
}

void Grid::initialize() {
	for (int row = 0; row < numrows; row++) {
		for (int column = 0; column < numcols; column++) {
			grid[row][column] = 0;
		}
	}
}
void Grid::print() {
	for (int row = 0; row < numrows; row++) {
		for (int column = 0; column < numcols; column++) {
			std::cout << grid[row][column] << " ";
		}
		std::cout << std::endl;
	}
}
void Grid::Draw() {
	for (int row = 0; row < numrows; row++) {
		for (int column = 0; column < numcols; column++) {
			int cellvalue = grid[row][column];
			DrawRectangle(column * cellsize+1,row * cellsize+1, cellsize-1,cellsize-1,colors[cellvalue]);
		}
	}
}

bool Grid::iscellout(int row, int column) {
	if (row >= 0 && row < numrows && column >= 0 && column < numcols) {
		return false;
	}
	return true;
}