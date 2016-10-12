#pragma once
#include <iostream>
#include "Battleship.h"
class Board
{
public:
	Board();
	~Board();

	void PrintBoard();
	void CheckGrid(const int x, const int y);
	int GetScore();

private:
	int score;
	bool board[5][5];
	Battleship ships[3];
	void PlaceShips();
	bool isSafePlacement(const int x, const int y, const int direction);
	bool isSafe(const int x, const int y);
};

