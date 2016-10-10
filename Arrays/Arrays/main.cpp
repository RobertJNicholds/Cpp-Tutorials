#include <iostream>

using namespace std;

float calc_avg(const int* arr, const int val) {
	int sum = 0;

	for (int i = 0; i < val; ++i)
		sum += arr[i];

	return (sum / (float)val);
}

float calc_avg(const int* arr, const int val);
void print_array(const char* arr);

int main(void) {
	const int CONST_VALUE = 3;
	float ave;

	// stack based 1-d arrays
	int array_nums[CONST_VALUE] = { 2, 4, 5 };

	// print out the first element
	cout << "value at index 0 is " << array_nums[0] << "\n";

	//stack based 2-d arrays
	char naughts_n_xs[3][3];

	// set the middle square to x
	naughts_n_xs[1][1] = 'X';

	//arrays on the heap 1-d
	int* sum = new int[CONST_VALUE];

	for (int i = 0; i < CONST_VALUE; ++i)
	{
		cout << "enter a value...\n";
		cin >> sum[i];
	}

	ave = calc_avg(sum, CONST_VALUE);

	cout << "the average is " << ave << "\n";

	delete[] sum;

	char fullname[]{ 'R', 'o', 'b', ' ', 'N', 'i','c','h','o','l','d','s', '\0' };
	print_array(fullname);

	char* firstname = new char[3];
	firstname[3] = '\0';
	char* lastname = new char[8];
	lastname[8] = '\0';

	for (unsigned int count = 0; count < 3; count++)
	{
		firstname[count] = fullname[count];
	}

	print_array(firstname);

	for (unsigned int count = 0; count < 8; count++)
	{
		lastname[count] = fullname[count + 4];
	}

	print_array(lastname);

	int z;
	std::cin >> z;

	delete[] firstname;
	delete[] lastname;

	return 0;
}

void print_array(const char* arr)
{	
	cout << arr << endl;
}
