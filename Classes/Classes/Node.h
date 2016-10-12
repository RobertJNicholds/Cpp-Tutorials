#pragma once
class Node
{
public:
	Node(int value) : value(value), left(NULL), right(NULL)
	{
	
	}
	~Node()
	{

	}

	int value;
	Node* left;
	Node* right;
};

