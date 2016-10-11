#pragma once
#include <iostream>
class Player
{
public:
	Player(int hps, int scorenum);
	~Player();
	int get_hit_points() const;
	int get_score() const;
	std::string get_name() const;
	void set_hit_points(int new_hit_points);
	void set_score(int new_score);
	void set_name(std::string new_name);
private:
	int hit_points;
	int* score;
	std::string* name;
};

