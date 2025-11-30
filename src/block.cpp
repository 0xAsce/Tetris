#include "block.h"

Block::Block() {
	cellsize = 30;
	rotationstate = 0;
	colors = getcellcolors();
	rowoffset = 0;
	columnoffset = 0;
}

void Block::Draw() {
	std::vector<Position> tiles = getcellposition();
	for (Position item : tiles) {
		DrawRectangle(item.column * cellsize + 1, item.row * cellsize + 1, cellsize - 1, cellsize - 1, colors[id]);
	}
}

void Block::Move(int rows, int columns) {
	rowoffset += rows;
	columnoffset += columns;
}

std::vector<Position> Block::getcellposition() {
	std::vector<Position> tiles = cells[rotationstate];
	std::vector<Position> movetiles;
	for (Position item : tiles) {
		Position newpos = Position(item.row + rowoffset, item.column + columnoffset);
		movetiles.push_back(newpos);
	}
	return movetiles;
}