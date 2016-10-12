#include <iostream>
#include "Board.h"

using namespace std;

int main()
{
	Board b;
	b.PrintBoard();
	b.CheckGrid(0, 2);

	int exit;
	cin >> exit;
	return 0;
}