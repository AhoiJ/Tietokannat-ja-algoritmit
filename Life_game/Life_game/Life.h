#pragma once

const int maxrow = 20, maxcol = 50;    //  grid dimensions default 20 x 50

class Life {
public:
	void initialize();
	void print();
	void update();
	void save();
private:
	int rows, cols;
	int grid[maxrow + 2][maxcol + 2];  //  allows for two extra rows and columns
	int neighbor_count(int row, int col);
	bool legal_position(int row, int col);
};
