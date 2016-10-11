#include <iostream>
#include "BinaryTree.h"

using namespace std;

class Enemy {
public:
	Enemy(int hps, int scorenum);
	~Enemy();
	int get_hit_points() const;
	int get_score() const;
	void set_hit_points(int new_hit_points);
	void set_score(int new_score);
private:
	int hit_points;
	int* score;
};

Enemy::Enemy(int hps, int scorenum) :
	hit_points(hps) {
	score = new int(scorenum);
}

Enemy::~Enemy() {
	delete score;
}

int Enemy::get_hit_points() const {
	return hit_points;
}

int Enemy::get_score() const {
	return *score;
}

void Enemy::set_hit_points(const int new_hit_points) {
	hit_points = new_hit_points;
}

void Enemy::set_score(const int new_score) {
	*score = new_score;
}

int main(void) {

	BinaryTree tree;

	tree.insert_integer(2);
	tree.insert_integer(5);
	tree.insert_integer(10);
	if (tree.contains_value(5))
		cout << "found 5" << endl;

	tree.print_tree();

	tree.destroy_tree();

	Enemy e1(2, 2);
	cout << "hit points = " << e1.get_hit_points() << "\n";

	Enemy* e2 = new Enemy(2, 2);
	e2->set_hit_points(3);
	cout << "hit points = " << e2->get_hit_points() << "\n";

	e2->set_score(2);
	cout << "score = " << e2->get_score() << "\n";

	delete e2;
	e2 = NULL;

	int exit;
	cin >> exit;
	return 0;
}
