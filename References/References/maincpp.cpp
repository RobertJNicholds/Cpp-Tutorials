#include <iostream>

using namespace std;

void swap(int x, int y) {
	int temp = x;
	x = y;
	y = temp;
}

void swap(int* x, int* y) {
	int temp = *x;
	*x = *y;
	*y = temp;
}

void swap_ref(int& x, int& y) {
	int temp = x;
	x = y;
	y = temp;
}

int nums[10]{ 7,3,5,2,1,4,6,9,10,8 };

void sort(int* nums_arr)
{
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (nums_arr[j] > nums_arr[j + 1])
			{
				swap_ref(nums_arr[j], nums_arr[j + 1]);
			}
		}
	}
}

int main() {
	int a, b;

	cout << "Please type in a number" << "\n";
	cin >> a;
	cout << "Please type in another number" << "\n";
	cin >> b;

	cout << "before swap, a = " << a << " and b = " << b << "\n";
	swap(a, b);
	cout << "after swap (by value), a = " << a << " and b = " << b << "\n";
	swap(&a, &b);
	cout << "after swap by pointer reference, a = " << a << " and b = " << b << "\n";

	swap_ref(a, b);
	cout << "after swap using references, a = " << a << " and b = " << b << "\n";

	int& a_ref = a;
	
	cout << "Array before sort = ";
	for (int i = 0; i < 10; i++)
	{
		cout << ' ' << nums[i];
	}
	cout << endl;

	sort(&nums[0]);

	cout << "Array after sort = ";

	for (int i = 0; i < 10; i++)
	{
		cout << ' ' << nums[i];
	}
	cout << endl;
	int z;
	cin >> z;

	return 0;
}
