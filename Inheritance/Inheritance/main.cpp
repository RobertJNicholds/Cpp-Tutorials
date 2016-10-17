#include <iostream>
#include "Enemy.h"
#include "Boss.h"
#include "BinaryTree.h"
#include "Matrix.h"
#include "ComplexNumber.h"
#include "Vector3.h"
#include "stack.h"

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

	cout << armed_enemies[0] << endl;

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

	BinaryTree<Vector3<double>> vector3_tree;

	
	vector3_tree.insert_value(Vector3<double>(10.0, 1.0, 3.0));
	vector3_tree.insert_value(Vector3<double>(15.5, 2.0, 6.0));
	vector3_tree.insert_value(Vector3<double>(5.0, 6.0, 8.0));
	vector3_tree.insert_value(Vector3<double>(1.0, 1.0, 1.0));

	cout << "Value stored in Vector3_tree are " << endl;
	vector3_tree.print_tree();
	vector3_tree.destroy_tree();
	cout << endl;

	Vector3<int> vec1(1, 1, 1);
	Vector3<int> vec2(2, 3, 4);	
	
	cout << vec1.Dot(vec2) << endl;	
	cout << vec1.Cross(vec2) << endl;
	cout << vec1 * 5 << endl;

	cout << (vec1 == vec2) << endl;
	cout << vec1 + vec2 << endl;
	vec1 = vec2;
	cout << vec1 << endl;

	stack<int> ints;

	ints.push(5);
	ints.push(6);
	ints.push(2);

	cout << ints.get_size() << endl;
	ints.pop();
	cout << ints.get_size() << endl;

	Matrix<int> test_mat1;
	Matrix<int> test_mat2;

	for (int i = 0; i < test_mat1.default_x; ++i)
	{
		for (int j = 0; j < test_mat1.default_y; ++j)
		{
			test_mat1.set_element(i, j, 5);
		}
	}

	for (int i = 0; i < test_mat2.default_x; ++i)
	{
		for (int j = 0; j < test_mat2.default_y; ++j)
		{
			test_mat2.set_element(i, j, 5);
		}
	}

	test_mat1 = test_mat1 + test_mat2;
	test_mat1 = test_mat1 - test_mat2;

	ComplexNumber C1(5, 2);
	ComplexNumber C2(10, 6);

	cout << C2 - C1 << endl;
	

	delete ae;
	ae = NULL;

	int exit;
	cin >> exit;

	return 0;
}
