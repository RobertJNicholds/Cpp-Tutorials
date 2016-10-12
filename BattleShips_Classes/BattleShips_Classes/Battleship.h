#pragma once
#include <iostream>
class Battleship
{
public:
	Battleship();
	~Battleship();

	int get_hitpoints();	
	void set_location(const int x, const int y, const int idx);
	bool check_location(const int x, const int y);

private:

	struct Point
	{
		int x;
		int y;
	};

	int hitpoints;	
	Point locations[3];
};

