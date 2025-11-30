#pragma once
#include "grid.h"
#include "blocks.cpp"

class Game {
public:
	Game();
	Block getrandomblock();
	std::vector<Block> getallblocks();
	Grid grid;
	void Draw();
private:
	std::vector<Block> blocks;
	Block currentblock;
	Block nextblock;
};