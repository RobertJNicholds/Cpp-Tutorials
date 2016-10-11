#include "Battleship.h"

Battleship::Battleship(int hps) : hitpoints(hps), score(0)
{
}

Battleship::~Battleship()
{
}

int Battleship::get_hitpoints()
{
	return hitpoints;
}

int Battleship::get_score()
{
	return score;
}
