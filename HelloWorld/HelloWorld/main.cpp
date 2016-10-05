#include <iostream>
#include <string>

using namespace std;

char GetMiddleOfString(const string s);

int main() 
{
	const char a = 'a';
	const bool b = true;
	const double myDouble = 1.12;
	cout << "Hello" << ' ' << "World" << "\n";
	cout << "Char" << ' ' << a << "\n";
	cout << "Bool" << ' ' << b << "\n";
	cout << "Double" << ' ' << myDouble << "\n";

	cout << "Enter your first name" << "\n";
	string name;
	getline(cin, name);
	cout << "Your first name is" << ' ' << name << "\n";	
	cout << "Middle charcter of your name is" << ' ' << GetMiddleOfString(name) << "\n";

	string x;
	string y;

	std::cout << "Enter number 1" << "\n";
	cin >> x;

	std::cout << "Enter number 2" << "\n";
	cin >> y;

	cout << stoi(x) + stoi(y) << "\n";
	cout << stoi(x) * stoi(y) << "\n";

	return 0;
}

char GetMiddleOfString(const string s)
{
	int middle = s.length() >> 1;
	return s[middle];
}
