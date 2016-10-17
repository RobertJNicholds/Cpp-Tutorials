#include "ArmedEnemy.h"

ArmedEnemy::ArmedEnemy(const ArmedEnemy &src) : Enemy(src.hit_points), ammo_level(src.ammo_level)
{
	*score = *src.score;
}

void ArmedEnemy::set_score(const int new_score) {
	*score = new_score;
	cout << "score is now " << *score << "\n";
}

void ArmedEnemy::set_ammo(const int new_ammo)
{
	ammo_level = new_ammo;
	cout << "ammo is now " << ammo_level << "\n";
}


void ArmedEnemy::shoot() {
	if (ammo_level > 0) {
		cout << "bang!\n";
		--ammo_level;
	}
	else {
		cout << "out of ammo\n";
	}
}