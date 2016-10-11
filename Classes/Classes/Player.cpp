#include "Player.h"

Player::Player(int hps, int scorenum) : hit_points(hps)
{
	score = new int(scorenum);
}

Player::~Player()
{
	delete score;
}

int Player::get_hit_points() const {
	return hit_points;
}

int Player::get_score() const {
	return *score;
}

std::string Player::get_name() const
{
	return *name;
}

void Player::set_hit_points(const int new_hit_points) {
	hit_points = new_hit_points;
}

void Player::set_score(const int new_score) {
	*score = new_score;
}

void Player::set_name(const std::string new_name)
{
	*name = new_name;
}
