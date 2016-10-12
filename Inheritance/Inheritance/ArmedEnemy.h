#include "Enemy.h"
#include <iostream>

using namespace std;

class ArmedEnemy : public Enemy
{
public:
	ArmedEnemy();
	ArmedEnemy(int hps, int ammo);
	virtual ~ArmedEnemy();
	virtual void set_score(const int new_score);
	virtual void shoot();
protected:
	int ammo_level;
};

