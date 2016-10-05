#include <iostream>

using namespace std;

void swap(int* a, int* b);
void printEvenValues(int* a);

int main() {

	

	int a = 100;
	int d = 50;

	cout << "Value in memory location a is " << a << "\n";

	cout << "Address of (the reference to) memory location a is " << &a << "\n";

	int *b = &a;
	int *e = &d;

	swap(b, e);

	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
	printEvenValues(&arr[0]);

	cout << "Value in memory location pointed to by b is " << *b << "\n";


	cout << "Value in memory location b is " << b << "\n";
	cout << b << " should be the same as the memory location for a: " << &a << "\n";
	cout << "b is actually at memory location " << &b << endl;

	int** c;

	c = &b;
	cout << "c is now pointing to what b points to: " << **c << endl;

	cout << "c points to: " << *c << endl;

	cout << "c actually holds the value: " << c << endl;
	cout << c << " is the same value as b's memory location: " << &b << endl;
	cout << "c is actually at memory location " << &c << endl;

	cout << "c is eventually retrieving what is in memory location " << **&c << endl;
	cout << "the value of a is in memory location " << &a << endl;

	int x;
	cout << "Type in a number to finish" << "\n";
	cin >> x;

	return 0;
}

void swap(int* a, int* b)
{
	cout << "a before =" << *a << endl;
	cout << "b before =" << *b << endl;
	int temp = *a;
	*a = *b;
	*b = temp;
	cout << "a after =" << *a << endl;
	cout << "b after =" << *b << endl;
}

void printEvenValues(int* a)
{
	a++;
	cout << *a << endl;
	a += 2;
	cout << *a << endl;
	a += 2;
	cout << *a << endl;
	a += 2;
	cout << *a << endl;
	a += 2;
	cout << *a << endl;
}
