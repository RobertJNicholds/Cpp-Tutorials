#pragma once
#include <iostream>
#include "Node.h"
class BinaryTree
{
public:
	BinaryTree();
	~BinaryTree();

	void insert_integer(int value);
	void print_tree();
	void destroy_tree();
	bool contains_value(int value);

private:
	
	void insert_integer(Node** node, int value);
	void print_tree(Node* node);
	void destroy_tree(Node* node);
	bool contains_value(Node* node, int value);
	Node* root = NULL;
};

