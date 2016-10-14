#include "ArmedEnemy.h"

ArmedEnemy::ArmedEnemy() : Enemy(3), ammo_level(0)
{

}

ArmedEnemy::ArmedEnemy(int hps, int ammo) :
	Enemy(hps),
	ammo_level(ammo) {
}

ArmedEnemy::~ArmedEnemy() {
}

void ArmedEnemy::set_score(const int new_score) {
	*score = new_score;
	cout << "score is now " << *score << "\n";
}

void ArmedEnemy::shoot() {
	if (ammo_level > 0)
	{
		cout << "bang!\n";
		--ammo_level;
	}
	else
	{
		cout << "out of ammo\n";
	}
}

ostream& operator<<(ostream& ostr, const ArmedEnemy &rhs)
{
	ostr << "Armed Enemy ( Hit Points = " << rhs.hit_points
		<< " Amoo = " << rhs.ammo_level << " )";
	return ostr;
}
