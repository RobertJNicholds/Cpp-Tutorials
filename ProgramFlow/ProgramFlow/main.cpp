#include <iostream>

using namespace std;

int add(int x, int y) {
	return x + y;
}

int fac(int x) {

	int facSum = 1;

	for (int count = x; count > 0; count--)
		facSum = facSum * count;

	return facSum;
}

bool GreaterThanZero(int x)
{
	if (x >= 0)
		return true;

	cout << "Success" << endl;
	return false;
}

void LookForNegative()
{
	int input = 0;
	while (GreaterThanZero(input))
	{
		cin >> input;
	}
}

int factorial(int x)
{
	int facSum = 1;
	if (x < 1) return 1;
	return facSum = x * factorial(x - 1);
}

int main() {

	cout << "Please enter a number" << endl;
	int input;
	cin >> input;

	cout << factorial(input) << endl;
	cout << "Please enter a negative number" << endl;
	LookForNegative();
	int total = 0;
	int x;

	cout << "Please enter numbers, will finish if sum of factorals exceeds 2000" << "\n";

	while (total <= 2000) {
		cin >> x;
		total = add(fac(x), total);
	}

	cout << "The total is " << total << "\n";

	if (total > 3000)
		cout << "you overshot by a lot!" << "\n";
	else {
		cout << "You just went over" << "\n";
		cout << "Only over by " << total - 2000 << "\n";
	}

	cout << "enter a number to exit" << "\n";

	cin >> x;

	return 0;
}
