#pragma once
#include <iostream>
#include "ComparableObject.h"
template<class T, class Comparable>
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

	void insert_integer(Comparable** node, int value);
	void print_tree(Comparable* node);
	void destroy_tree(Comparable* node);
	bool contains_value(Comparable* node, int value);
	Comparable* root = NULL;
};

