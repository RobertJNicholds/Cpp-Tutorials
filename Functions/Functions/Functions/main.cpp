#include <iostream>
#include <string>
#include <math.h>

using namespace std;

int add(const int &x, const int &y);
int subtract(const int &x, const int &y);
int product(const int &x, const int &y);
double quotient(const double &x, const int &y);
void calculate(const int &x, const int &y, const char &operation);
void processInput();

int main() {

	int exit;		
	processInput();

	cout << "enter another number to exit" << "\n";
	cin >> exit;

	return 0;
}
int add(const int &x, const int &y) 
{

	cout << x << '+' << y << '=' << x + y << endl;
	return x + y;
}

int subtract(const int &x, const int &y)
{
	cout << x << '-' << y << '=' << x - y << endl;
	return x - y;
}

int product(const int &x, const int &y)
{
	int result = x * y;
	cout << x << '*' << y << '=' << result << endl;
	return result;
}

double quotient(const double &x, const int &y)
{
	double result;
	result = x / y;
	cout << x << '/' << y << '=' << result << endl;
	return result;
}

void calculate(const int &x, const int &y, const char &operation)
{
	switch (operation)
	{	
	default:
		cout << "Invalid Operation" << endl;
		processInput();
		break;
	case '+':
		add(x, y);
		break;
	case '-':
		subtract(x, y);
		break;
	case '*':
		product(x, y);
		break;
	case '/':
		quotient(x, y);
		break;
	case '^':
		cout << x << '^' << y << '=' << pow(x, y) << endl;
		break;		
	}
}

void processInput()
{
	string input;
	cin >> input;

	string delimiter[5]{ "+", "-", "*", "/", "^" };
	string found_delim;
	size_t position = 0;
	string value;

	int numbers[2];
	int num_count = 0;

	for (unsigned int count = 0; count < 5; count++)
	{
		while ((position = input.find(delimiter[count])) != string::npos)
		{
			value = input.substr(0, position);			
			numbers[0] = stoi(input);
			
			input.erase(0, position + delimiter[count].length());
			if (input.length() < 3)
				found_delim = delimiter[count];
				break;
		}
	}

	try 
	{
		numbers[1] = stoi(input);
	}
	catch (...)
	{
		cout << "Error invalid entry" << endl;
		processInput();
	}
	calculate(numbers[0], numbers[1], *found_delim.c_str());	
}
