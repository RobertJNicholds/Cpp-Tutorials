#include "Battleship.h"

Battleship::Battleship() : hitpoints(3)
{
}

Battleship::~Battleship()
{
}

int Battleship::get_hitpoints()
{
	return hitpoints;
}

void Battleship::set_location(const int x, const int y, const int idx)
{
	locations[idx].x = x;
	locations[idx].y = y;
}

bool Battleship::check_location(const int x, const int y)
{
	for (int i = 0; i < 3; ++i)
	{
		if (locations[i].x == x && locations[i].y == y)
		{
			hitpoints--;
			std::cout << "OW" << std::endl;
			return true;
		}
	}

	return false;
}
