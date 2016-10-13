#pragma once
template <typename T>
class Comparable
{
public:
	Comparable(T value) : value(value) {};
	~Comparable() {};	
	
	int compare_to(const Comparable &rhs)
	{
		if (value > rhs.value)
			return 0;

		else
			return -1;
	}	

	T value;
	Comparable* left;
	Comparable* right;
	
};

