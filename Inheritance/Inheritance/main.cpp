#include <iostream>
#include "Enemy.h"
#include "Boss.h"
#include "BinaryTree.h"

using namespace std;

void some_function(Enemy& enemy) {
	enemy.set_score(6);
}

void decreaseHitPoints(Enemy& enemy)
{
	enemy.set_hit_points(enemy.get_hit_points() - 1);
}

int main(void) {

	ArmedEnemy* ae = new ArmedEnemy(2, 5);
	ae->set_hit_points(3);
	cout << "hit points = " << ae->get_hit_points() << "\n";

	Boss* boss = new Boss(2, 5, 2);

	ArmedEnemy armed_enemies[10];

	Enemy** enemies = new Enemy*[11];

	for (int i = 0; i < 10; ++i)
	{
		enemies[i] = &armed_enemies[i];
		cout << "Enemy " << i << " Hit Points = " << enemies[i]->get_hit_points() << endl;
	}

	enemies[10] = boss;

	for (int i = 0; i < 11; ++i)
	{
		decreaseHitPoints(*enemies[i]);
		cout << "Enemy " << i << " Hit Points = " << enemies[i]->get_hit_points() << endl;
	}


	cout << "Boss armour = " << boss->getArmour() << "\n";

	ae->shoot();

	some_function(*ae);

	BinaryTree<int, ComparableObject<int>> tree;
	tree.insert_integer(2);
	tree.print_tree();

	delete ae;
	ae = NULL;

	int exit;
	cin >> exit;

	return 0;
}
