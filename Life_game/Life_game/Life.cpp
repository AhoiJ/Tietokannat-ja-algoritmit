#include <iostream>
#include "Life.h"
#include <fstream>
#include <string>

using namespace std;

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

	for (row = 1; row <= this -> rows; row++)
		for (col = 1; col <= this -> cols; col++)
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

	for (row = 0; row <= this -> rows; row++)
		for (col = 0; col <= this -> cols; col++)
			grid[row][col] = new_grid[row][col];
}

void Life::save()
{
	string board[maxrow][maxcol];

	// riippuen gamestatesta, eli sen update vaiheesta
	// gridin dead cellit näyttävät negatiivisia virheellisiä lukuja

	for (int i = 0; i < this->rows; i++) {
		for (int u = 0; u < this->cols; u++)
		{
			if (grid[i][u] == 1)
				board[i][u] = "x";
			else
				board[i][u] = " ";

		}
	}

	std::ofstream out("output.txt");
	for (int i = 0; i < this->rows; i++)
	{
		for (int u = 0; u < this->cols; u++)
		out <<  grid[i][u];
	}
	out.close();
}

void Life::initialize()
/*
Pre:  None.
Post: The Life object contains a configuration specified by the user.
*/

{

	int row, col;
	
	
	std::cout << "Enter grid size, use the max, maximum 20 x 50 and minimum 10 x 10." << std::endl;
	int checker = 0;
	while (checker < 2)
	{
		std::cout << "Number of rows: ";
		std::cin >> this->rows;
		std::cout << "Number of cols: ";
		std::cin >> this -> cols;
	if (rows >= 10 && cols >= 10)
	checker++;
	else
	std::cout << "Gridsize error" << std::endl;
	if (rows <= 20 && cols <= 50)
	checker++;
	else if(checker == 1)
	std::cout << "Gridsize error" << std::endl;
	}

	/*
	for (row = 0; row <= rows + 1; row++)
		for (col = 0; col <= cols + 1; col++)
			grid[row][col] = 0;
	std::cout << "List the coordinates for living cells." << std::endl;
	std::cout << "Terminate the list with the special pair -1 -1" << std::endl;
	std::cin >> row >> col;
	*/
		std::cout << "Fill the board with x or spacebar. " << std::endl;
		std::string board[maxrow][maxcol];

		for (int i = 0; i < maxrow; i++)
			for (int u = 0; u < maxcol; u++)
				board[i][u] = "";
		
		for (int i = 0; i < rows; i++)
			for (int u = 0; u < cols; u++) {
				if (u % 2 == 0 )
					board[i][u] = "x"; //	for tests
				else board[i][u] = " ";

			//	std::getline(std::cin, board[i][u]);
	}
/*	Prints board for tests
		for (int i = 0; i < rows; i++) {
			for (int u = 0; u < cols; u++) {
				std::cout << board[i][u];
			}
			std::cout << std::endl;
		}*/

		for (row = 0; row <= this->rows + 1; row++)
			for (col = 0; col <= this->cols + 1; col++)
				grid[row][col] = 0;


		// laittaa syötetyn boardin tarkistettavaan gridiin
		for (int i = 0; i < this -> rows; i++){
			for (int u = 0; u < this -> cols; u++)
			{
				if (board[i][u] == "x")
					grid[i][u] = 1;
				else 
					grid[i][u] = 0;

			}
		}
		

	/*
	while (row != -1 || col != -1) {
		if (row >= 1 && row <= this -> rows)
			if (col >= 1 && col <= this -> cols)
				grid[row][col] = 1;
			else
				std::cout << "Column " << col << " is out of range." << std::endl;
		else
			std::cout << "Row " << row << " is out of range." << std::endl;
		std::cin >> row >> col;
	}
	*/
}


void Life::print()
/*
Pre:  The Life object contains a configuration.
Post: The configuration is written for the user.
*/

{
	int row, col;
	std::cout << "\nThe current Life configuration is:" << std::endl;
	for (row = 1; row <= this -> rows; row++) {
		for (col = 1; col <= this -> cols; col++)
			if (grid[row][col] == 1) std::cout << '*';
			else std::cout << ' ';
			std::cout << std::endl;
	}
	std::cout << std::endl;
}

bool Life::legal_position(int row, int col)
{
	return (0 <= row && row < maxrow && 0 <= col && col < maxcol);
}