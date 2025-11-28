#include "block.h"

Block::Block() {
	cellsize = 30;
	rotationstate = 0;
	colors = getcellcolors();
}

void Block::Draw() {
	std::vector<Position> tiles = cells[rotationstate];
	for (Position item : tiles) {
		DrawRectangle(item.column * cellsize + 1, item.row * cellsize + 1, cellsize - 1, cellsize - 1, colors[id]);
	}
}