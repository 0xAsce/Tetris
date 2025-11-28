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
	int id;
	std::map<int, std::vector<Position>> cells;

private:
	int cellsize;
	int rotationstate;
	std::vector<Color> colors;
};