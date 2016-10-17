#include <iostream>
#include "Enemy.h"
#include "ArmedEnemy.h"
#include <vector>
#include <algorithm>
#include <random>

using namespace std;
using std::vector;

bool sortByScore(ArmedEnemy &lhs, ArmedEnemy &rhs) { return lhs.get_score() < rhs.get_score(); }

int main() {

	vector<int> scores(5, 0);

	scores[0] = 1; scores[1] = 2; scores[2] = 3;

	for (unsigned int i = 0; i < scores.size(); ++i) {
		cout << "scores " << i << " = " << scores[i] << "\n";
	}

	vector<Enemy>* enemies = new vector<Enemy>(3);	

	Enemy fourth, fifth;

	enemies->push_back(fourth);
	enemies->push_back(fifth);
	cout << "size of enemies = " << enemies->size() << "\n";

	int i = 0;
	for (vector<Enemy>::iterator it = enemies->begin(); it != enemies->end(); ++it)
	{
		it->set_score(scores[i]);
		cout << "score = " << it->get_score() << "\n";
		++i;
	}

	Enemy newthird;
	enemies->insert(enemies->begin() + 2, newthird);
	enemies->erase(enemies->begin() + 2);

	Enemy& back = enemies->back();
	cout << "hit points last element = " << back.get_hit_points() << "\n";

	enemies->pop_back();
	cout << "new size of enemies = " << enemies->size() << "\n";

	vector<ArmedEnemy> armed_enemies(10);

	for (vector<ArmedEnemy>::iterator it = armed_enemies.begin(); it != armed_enemies.end(); ++it)
	{
		it->set_score(rand() % 20);
		
		//cout << it->get_ammo() << endl;
	}

	auto engine = default_random_engine{};
	shuffle(begin(armed_enemies), end(armed_enemies), engine);

	for (vector<ArmedEnemy>::iterator it = armed_enemies.begin(); it != armed_enemies.end(); ++it)
	{		
		cout << it->get_score() << endl;
	}

	sort(begin(armed_enemies), end(armed_enemies), sortByScore);

	for (vector<ArmedEnemy>::iterator it = armed_enemies.begin(); it != armed_enemies.end(); ++it)
	{
		cout << it->get_score() << endl;
	}
	
	// clear enemies of elements
	enemies->clear();
	delete enemies;

	int exit;
	cin >> exit;

	
	return 0;
}