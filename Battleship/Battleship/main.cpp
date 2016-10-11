#include <iostream>
#include <string>
#include <time.h>

using namespace std;

bool guess_grid[5][5]{ false, false ,false, false, false,
					false, false, false, false, false,
					false, false, false, false, false,
					false, false, false, false, false,
					false, false, false, false, false };

void print_guesses();
void check_grid(const int x, const int y, int* guess_count, bool grid[][5]);
void create_grid(int num_of_ships, bool grid[][5]);
bool check_bounds(const int x,const int y);
bool isSafePlacement(const int x, const int y, const int direction, bool grid[][5]);
bool isSafe(const int x, const int y, bool grid[][5]);

int main()
{	
	bool grid[5][5];
	srand(static_cast<unsigned int>(time(NULL)));
	int num_of_ships = 2;
	create_grid(num_of_ships, grid);

	int guess_count = 5;

	while (guess_count > 0)
	{	
		print_guesses();
		cout << endl;
		cout << "Number of guesses remaining = " << guess_count << endl;
		cout << "Enter x coordinate" << endl;
		int x;
		cin >> x;
		cout << "Enter y coordinate" << endl;
		int y;
		cin >> y;

		check_grid(y, x, &guess_count, grid);
	}

	cout << "Game over!    Enter another number to exit" << endl;
	int exit;
	cin >> exit;
	
	return 0;
}

void check_grid(const int x, const int y, int* guess_count, bool grid[][5])
{
	if (x > 4 || y > 4 || x < 0 || y < 0)
	{
		//User entered values out of array bounds
		cout << "Invalid Coordinates" << endl << endl;
		return;
	}
	if (grid[x][y] == true)
	{
		//Success, update user displayed grid.
		system("cls");
		cout << "Hit!" << endl;
		cout << endl;
		grid[x][y] = false;
		guess_grid[x][y] = true;
		return;
	}

	//Failure, reduce number of guesses by 1
	system("cls");
	cout << "Miss!" << endl;
	cout << endl;
	*guess_count -= 1;
	return;
}

void print_guesses()
{
	// "O" represents location of hit ship parts
	// "X" unkown or miss
	for (int x = 0; x < 5; x++)
	{		
		for (int y = 0; y < 5; y++)
		{
			if (guess_grid[x][y] == true)
			{
				cout << "o ";
			}
			else
			{
				cout << "x ";
			}
		}
		cout << endl;
	}
}

void create_grid(int num_of_ships, bool grid[][5])
{
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			grid[i][j] = false;
		}
	}

	while(num_of_ships > 0)
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
			if (isSafePlacement(x, y, direction, grid))
			{
				grid[x][y] = true;
				grid[x][y - 1] = true;
				grid[x][y - 2] = true;
				num_of_ships--;
			}
			else			
				continue;
		//East	
		case 1:
			if (isSafePlacement(x, y, direction, grid))
			{
				grid[x][y] = true;
				grid[x + 1][y] = true;
				grid[x + 2][y] = true;
				num_of_ships--;
			}
			else
				continue;
		//South
		case 2:
			if (isSafePlacement(x, y, direction, grid))
			{
				grid[x][y] = true;
				grid[x][y + 1] = true;
				grid[x][y + 2] = true;
				num_of_ships--;
			}
			else
				continue;
		//West
		case 3:
			if (isSafePlacement(x, y, direction, grid))
			{
				grid[x][y] = true;
				grid[x - 1][y] = true;
				grid[x - 2][y] = true;
				num_of_ships--;
			}
			else
				continue;
		}
	}
}

bool isSafePlacement(const int x, const int y, const int direction, bool grid[][5])
{
	switch (direction)
	{
	default:
		return false;
	case 0:
		if (isSafe(x, y - 1, grid) && isSafe(x, y - 2, grid))
			return true;
		else
			return false;
	case 1:
		if (isSafe(x + 1, y, grid) && isSafe(x + 2, y, grid))
			return true;
		else
			return false;
	case 2:
		if (isSafe(x, y + 1, grid) && isSafe(x, y + 2, grid))
			return true;
		else
			return false;
	case 3:
		if (isSafe(x - 1, y, grid) && isSafe(x - 2, y, grid))
			return true;
		else
			return false;			
	}
}

bool isSafe(const int x, const int y, bool grid[][5])
{
	//Ship overlap, not safe
	if (grid[x][y] == true)
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
