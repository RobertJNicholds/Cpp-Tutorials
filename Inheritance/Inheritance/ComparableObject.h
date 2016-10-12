#pragma once
template <typename T>
class Node
{
public:
	Node(int value) : value(value) {};
	~Node() {};

	template<typename T>
	int compare_to(const Node& rhs)
	{
		if (value > rhs.value)
			return 0;

		else
			return -1;
	}

	T value;
	Node* left;
	Node* right;
};

