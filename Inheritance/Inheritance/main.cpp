#include <iostream>
#include "Enemy.h"
#include "Boss.h"
#include "BinaryTree.h"
#include "Vector3.h"

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

	BinaryTree<char> char_tree;
	
	char_tree.insert_value('e');
	char_tree.insert_value('d');
	char_tree.insert_value('c');
	char_tree.insert_value('a');
	
	cout << "Value stored in char_tree are " << endl;
	char_tree.print_tree();
	char_tree.destroy_tree();

	cout << endl;

	BinaryTree<double> double_tree;	

	double_tree.insert_value(6.0);
	double_tree.insert_value(2.0);
	double_tree.insert_value(10.0);
	double_tree.insert_value(7.6);

	cout << "Value stored in double_tree are " << endl;
	double_tree.print_tree();
	double_tree.destroy_tree();

	BinaryTree<Vector3<int>> vector3_tree;

	Vector3<int> vector(5, 6, 10);
	cout << vector.Magnitude() << endl;
	
	vector3_tree.insert_value(Vector3<int>(10, 1, 3));
	vector3_tree.insert_value(Vector3<int>(15, 2, 6));
	vector3_tree.insert_value(Vector3<int>(5, 6, 8));
	vector3_tree.insert_value(Vector3<int>(1, 1, 1));

	cout << "Value stored in Vector3_tree are " << endl;
	vector3_tree.print_tree();
	vector3_tree.destroy_tree();
	cout << endl;

	delete ae;
	ae = NULL;

	int exit;
	cin >> exit;

	return 0;
}
