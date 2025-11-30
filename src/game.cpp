#include "game.h"
#include <random>
Game::Game(){
	grid = Grid();
	blocks = getallblocks();
	currentblock = getrandomblock();
	nextblock = getrandomblock();
}
Block Game::getrandomblock() {
	if (blocks.empty()) {
		blocks = getallblocks();
	}
	int randomindex = rand() % blocks.size();
	Block block = blocks[randomindex];
	blocks.erase(blocks.begin() + randomindex);
	return block;
}

std::vector<Block> Game::getallblocks() {
	return { IBlock(),JBlock(),LBlock(),OBlock(),SBlock(),TBlock(),ZBlock() };
}

void Game::Draw() {
	grid.Draw();
	currentblock.Draw();
}