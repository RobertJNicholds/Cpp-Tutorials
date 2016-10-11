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

private:
	
	void insert_integer(Node** node, int value);
	void print_tree(Node* node);
	void destroy_tree(Node* node);
	Node* root = NULL;
};

