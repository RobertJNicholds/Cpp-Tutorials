#pragma once
#include "Enemy.h"
class ArmedEnemy : public Enemy {
public:
	static const int default_ammo = 8;
	ArmedEnemy() :Enemy(), ammo_level(default_ammo) {}
	ArmedEnemy(int hps, int ammo) :Enemy(hps), ammo_level(ammo) {}
	ArmedEnemy(const ArmedEnemy &src);
	virtual ~ArmedEnemy() {}
	virtual void set_score(const int new_score);	
	void set_ammo(const int new_ammo);
	int get_ammo() { return ammo_level; }
	virtual int get_score() const { return *score; }
	virtual void shoot();

protected:
	int ammo_level;
};




