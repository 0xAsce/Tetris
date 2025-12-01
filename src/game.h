#pragma once
#include "grid.h"
#include "blocks.cpp"

class Game {
public:
	Game();
	Block getrandomblock();
	std::vector<Block> getallblocks();
	void handleinput();
	void moveblockleft();
	void moveblockright();
	void moveblockdown();
	Grid grid;
	void Draw();
private:
	bool isblockoutside();
	void rotateblock();
	void lockblock();
	std::vector<Block> blocks;
	Block currentblock;
	Block nextblock;

};