#include "ArmedEnemy.h"

class Boss : public ArmedEnemy
{
public:

	Boss(int hps, int ammo, int armour);
	~Boss();

	int getArmour()
	{
		return armour;
	}

	void setArmour(int value)
	{
		armour = value;
	}

private:
	int armour;
};
