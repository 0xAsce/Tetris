#pragma once
#include <vector>
#include <raylib.h>
class Grid {
public:
	Grid();
	void initialize();
	void print();
	bool iscellout(int row,int column);
	int grid[20][10];
	void Draw();
private:
	int numrows;
	int numcols;
	int cellsize;
	std::vector<Color> colors;
};