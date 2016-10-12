#include "Board.h"

Board::Board() : score(0)
{
	for (int x = 0; x < 5; ++x)
	{
		for (int y = 0; y < 5; ++y)
		{
			board[x][y] = false;
		}
	}

	PlaceShips();
}

Board::~Board()
{
}

int Board::GetScore()
{
	return score;
}

void Board::PrintBoard()
{
	// "O" represents location of hit ship parts
	// "X" unkown or miss
	for (int x = 0; x < 5; ++x)
	{
		for (int y = 0; y < 5; ++y)
		{
			if (board[x][y] == true)
			{
				std::cout << "O ";
			}
			else
			{
				std::cout << "X ";
			}
		}
		std::cout << std::endl;
	}
}

void Board::CheckGrid(const int x, const int y)
{
	if (x > 4 || y > 4 || x < 0 || y < 0)
	{
		std::cout << "Invalid Coordinates" << std::endl;
		return;
	}

	if (board[x][y] == true)
	{
		//Correct Guess;
		std::cout << "Hit!" << std::endl;
		score++;
		
		for (int i = 0; i < 3; ++i)
		{
			ships[i].check_location(x, y);
		}
	}
}

void Board::PlaceShips()
{
	int num_of_ships = 3;

	while (num_of_ships > 0)
	{
		int x = rand() % 5;
		int y = rand() % 5;

		//Create random direction to place ship
		// 0 is North
		// 1 is East
		// 2 is South
		// 3 is West
		int direction = rand() % 4;


		switch (direction)
		{
			//North
		case 0:
			if (isSafePlacement(x, y, direction))
			{
				ships[num_of_ships].set_location(x, y, num_of_ships);
				ships[num_of_ships].set_location(x, y - 1, num_of_ships);
				ships[num_of_ships].set_location(x, y - 2, num_of_ships);
				board[x][y] = true;
				board[x][y - 1] = true;
				board[x][y - 2] = true;
				num_of_ships--;
			}
			else
				continue;
			//East	
		case 1:
			if (isSafePlacement(x, y, direction))
			{
				ships[num_of_ships].set_location(x, y, num_of_ships);
				ships[num_of_ships].set_location(x + 1, y, num_of_ships);
				ships[num_of_ships].set_location(x + 2, y, num_of_ships);
				board[x][y] = true;
				board[x + 1][y] = true;
				board[x + 2][y] = true;
				num_of_ships--;
			}
			else
				continue;
			//South
		case 2:
			if (isSafePlacement(x, y, direction))
			{
				ships[num_of_ships].set_location(x, y, num_of_ships);
				ships[num_of_ships].set_location(x, y + 1, num_of_ships);
				ships[num_of_ships].set_location(x, y + 2, num_of_ships);
				board[x][y] = true;
				board[x][y + 1] = true;
				board[x][y + 2] = true;
				num_of_ships--;
			}
			else
				continue;
			//West
		case 3:
			if (isSafePlacement(x, y, direction))
			{
				ships[num_of_ships].set_location(x, y, num_of_ships);
				ships[num_of_ships].set_location(x - 1, y, num_of_ships);
				ships[num_of_ships].set_location(x - 2, y, num_of_ships);
				board[x][y] = true;
				board[x - 1][y] = true;
				board[x - 2][y] = true;
				num_of_ships--;
			}
			else
				continue;
		}
	}
}

bool Board::isSafePlacement(int x, int y, int direction)
{
	switch (direction)
	{
	default:
		return false;
	case 0:
		if (isSafe(x, y - 1) && isSafe(x, y - 2))
			return true;
		else
			return false;
	case 1:
		if (isSafe(x + 1, y) && isSafe(x + 2, y))
			return true;
		else
			return false;
	case 2:
		if (isSafe(x, y + 1) && isSafe(x, y + 2))
			return true;
		else
			return false;
	case 3:
		if (isSafe(x - 1, y) && isSafe(x - 2, y))
			return true;
		else
			return false;
	}
}

bool Board::isSafe(const int x, const int y)
{
	//Ship overlap, not safe
	if (board[x][y] == true)
		return false;
	//X out of array bounds, not safe
	if (x < 0 || x > 4)
		return false;
	//Y out of array bounds, not safe
	if (y < 0 || y > 4)
		return false;

	//Passed all check, placement is safe
	return true;
}

