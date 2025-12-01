#pragma once
#include <vector>
#include <map>
#include "position.h"
#include "colors.h"
#include <raylib.h>

class Block {
public:
	Block();
	void Draw();
	void Move(int rows, int columns);
	std::vector<Position> getcellposition();
	int id;
	void undorotation();
	void rotate();
	std::map<int, std::vector<Position>> cells;

private:
	int cellsize;
	int rotationstate;
	std::vector<Color> colors;
	int rowoffset;
	int columnoffset;
};