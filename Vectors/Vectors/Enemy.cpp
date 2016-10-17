#include "Enemy.h"

/**
* copy constructor for enemy
*/
Enemy::Enemy(const Enemy& src) :
	hit_points(src.hit_points),
	score(new int(*src.score))
{
}

/**
* assignment operator for enemy
*/
Enemy& Enemy::operator=(const Enemy& rhs)
{
	if (this == &rhs) {
		return (*this);
	}
	//free old memory
	delete score;

	//copy new memory
	hit_points = rhs.hit_points;
	score = new int(*rhs.score);

	return *this;
}
