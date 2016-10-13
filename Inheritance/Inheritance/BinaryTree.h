#pragma once
#include <iostream>
#include "Comparable.h"

template<typename T>
class BinaryTree
{
public:

	BinaryTree();
	~BinaryTree();

	void insert_value(T value);
	void print_tree();
	void destroy_tree();
	bool contains_value(T value);	

private:

	void insert_value(Comparable<T>** node, Comparable<T> value);
	void print_tree(Comparable<T>* node);
	void destroy_tree(Comparable<T>* node);
	bool contains_value(Comparable<T>* node, T value);
	Comparable<T>* root = NULL;

};


template<typename T>
BinaryTree<T>::BinaryTree() : root(NULL)
{

}

template<typename T>
BinaryTree<T>::~BinaryTree()
{
}

template<typename T>
void BinaryTree<T>::insert_value(T new_value)
{
	insert_value(&root, new_value);
}

template<typename T>
void BinaryTree<T>::insert_value(Comparable<T>** node, Comparable<T> comparable)
{
	if ((*node) == NULL)
	{
		(*node) = new Comparable<T>(comparable.value);
		return;
	}

	if ((*node)->compare_to(comparable) == 0)
	{
		insert_value(&(*node)->left, comparable);
	}
	else
	{
		insert_value(&(*node)->right, comparable);
	}
}

template<typename T>
void BinaryTree<T>::print_tree()
{
	print_tree(root);
}

template<typename T>
void BinaryTree<T>::print_tree(Comparable<T>* node)
{
	if (node != NULL)
	{
		if (node->left != NULL)
		{
			print_tree(node->left);
		}

		std::cout << node->value << std::endl;

		if (node->right != NULL)
		{
			print_tree(node->right);
		}
	}
}

template<typename T>
void BinaryTree<T>::destroy_tree()
{
	destroy_tree(root);
}

template<typename T>
void BinaryTree<T>::destroy_tree(Comparable<T>* node)
{
	if (node->left != NULL)
		destroy_tree(node->left);
	if (node->right != NULL)
		destroy_tree(node->right);

	delete node;
}

template<typename T>
bool BinaryTree<T>::contains_value(T value)
{
	if (contains_value(root, value) == true)
	{
		return true;
	}

	return false;
}

template<typename T>
bool BinaryTree<T>::contains_value(Comparable<T>* node, T value)
{
	if (node->value == value)
	{
		return true;
	}

	if (node->left != NULL)
		if (contains_value(node->left, value))
			return true;
	if (node->right != NULL)
		if (contains_value(node->right, value))
			return true;

	return false;
}



