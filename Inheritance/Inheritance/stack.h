#pragma once
template <typename T>
class node
{
public:

	node() : value(0) {};
	node(T value) : value(value) {};

	T value;
	node<T>* next;
};

template<typename T>
class stack
{
public:
	
	stack();
	~stack();

	void push(T value);
	void pop();
	int get_size();
	bool is_empty();

private:

	node<T>* top;
};

template <typename T>
stack<T>::stack() : top(nullptr)
{

}

template <typename T>
stack<T>::~stack()
{
	node<T>* curr = top;
	while (top)
	{
		top = top->next;
	}
}

template <typename T>
void stack<T>::push(T value)
{
	node<T>* new_node = new node<T>(value);
	new_node->next = top;
	top = new_node;
}

template <typename T>
void stack<T>::pop()
{
	if (top == NULL)
	{
		return;
	}

	node<T>* first = top;
	top = first->next;
	delete first;
}

template<typename T>
int stack<T>::get_size()
{
	int count = 0;
	node<T>* curr = top;
	while (curr != NULL)
	{
		count++;
		curr = curr->next;		
	}

	return count;
}

template <typename T>
bool stack<T>::is_empty()
{
	if (top == NULL)
		return true;
}
