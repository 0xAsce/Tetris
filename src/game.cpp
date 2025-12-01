#include "game.h"
#include <random>
#include <iostream>
#include <ctime>
Game::Game(){
	std::srand(static_cast<unsigned int>(std::time(nullptr)));
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
void Game::handleinput() {
	int keypressed = GetKeyPressed();
	switch (keypressed)
	{
	case KEY_LEFT:
		moveblockleft();
		break;
	case KEY_RIGHT:
		moveblockright();
		break;
	case KEY_DOWN:
		moveblockdown();
		break;
	case KEY_UP:
		rotateblock();
		break;
	}
}

void Game::moveblockleft() {
	currentblock.Move(0, -1);
	if (isblockoutside()) {
		currentblock.Move(0, 1);
	}
}
void Game::moveblockright() {
	currentblock.Move(0, 1);
	if (isblockoutside()) {
		currentblock.Move(0, -1);
	}
}
void Game::moveblockdown() {
	currentblock.Move(1, 0);
	if (isblockoutside()) {
		currentblock.Move(-1, 0);
	}
}

bool Game::isblockoutside() {
	std::vector<Position> tiles = currentblock.getcellposition();
	for (Position item : tiles) {
		if (grid.iscellout(item.row, item.column)) {
			return true;
		}
	}
	return false;
} 
void Game::rotateblock() {
	currentblock.rotate();
	if (isblockoutside()) {
		currentblock.undorotation();
	}
}