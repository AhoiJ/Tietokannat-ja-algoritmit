#include <iostream>
#include "Life.h"
#include <iostream>

int Life::neighbor_count(int row, int col)

{
	int i, j;
	int count = 0;
	for (i = row - 1; i <= row + 1; i++)
		for (j = col - 1; j <= col + 1; j++)
			count += grid[i][j];  //  Increase the count if neighbor is alive.
	count -= grid[row][col]; //  Reduce count, since cell is not its own neighbor.
	return count;
}

void Life::update()
/*
Pre:  The Life object contains a configuration.
Post: The Life object contains the next generation of configuration.
*/

{
	int row, col;
	int new_grid[maxrow + 2][maxcol + 2];

	for (row = 1; row <= maxrow; row++)
		for (col = 1; col <= maxcol; col++)
			switch (neighbor_count(row, col)) {
			case 2:
				new_grid[row][col] = grid[row][col];  //  Status stays the same.
				break;
			case 3:
				new_grid[row][col] = 1;                //  Cell is now alive.
				break;
			default:
				new_grid[row][col] = 0;                //  Cell is now dead.
			}

	for (row = 1; row <= maxrow; row++)
		for (col = 1; col <= maxcol; col++)
			grid[row][col] = new_grid[row][col];
}

void Life::initialize()
/*
Pre:  None.
Post: The Life object contains a configuration specified by the user.
*/

{
	/*
	std::cout << "Enter grid size, maximum 50 x 50 and minimum 10 x 10." << std::endl;
	int checker = 0;
	int maxcol = 0; // maxrow and maxcol still as const int in header file
	int maxrow = 0; 
	while (checker < 2)
	{
		std::cin >> maxrow >> maxcol;
		if (maxrow >= 10 && maxcol >= 10)
			checker++;
		else
			std::cout << "Gridsize error" << std::endl;
		if (maxrow <= 50 && maxcol <= 50)
			checker++;
		else if(checker == 1)
			std::cout << "Gridsize error" << std::endl;
	}
	*/
	int row, col;
	for (row = 0; row <= maxrow + 1; row++)
		for (col = 0; col <= maxcol + 1; col++)
			grid[row][col] = 0;
	std::cout << "List the coordinates for living cells." << std::endl;
	std::cout << "Terminate the list with the special pair -1 -1" << std::endl;
	std::cin >> row >> col;

	while (row != -1 || col != -1) {
		if (row >= 1 && row <= maxrow)
			if (col >= 1 && col <= maxcol)
				grid[row][col] = 1;
			else
				std::cout << "Column " << col << " is out of range." << std::endl;
		else
			std::cout << "Row " << row << " is out of range." << std::endl;
		std::cin >> row >> col;
	}
}


void Life::print()
/*
Pre:  The Life object contains a configuration.
Post: The configuration is written for the user.
*/

{
	int row, col;
	std::cout << "\nThe current Life configuration is:" << std::endl;
	for (row = 1; row <= maxrow; row++) {
		for (col = 1; col <= maxcol; col++)
			if (grid[row][col] == 1) std::cout << '*';
			else std::cout << ' ';
			std::cout << std::endl;
	}
	std::cout << std::endl;
}

