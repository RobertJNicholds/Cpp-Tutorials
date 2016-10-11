#pragma once
class Battleship
{
public:
	Battleship(int hps);
	~Battleship();

	int get_hitpoints();
	int get_score();

private:
	int hitpoints;
	int score;
};

