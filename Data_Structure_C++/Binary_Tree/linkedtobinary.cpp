#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class  link_list
{
public:
	int data;
	link_list *next;
	 link_list(int data)
	 {
	 	this->data = data;
	 	next = nullptr;
	 }
};

class binary_tree
{
public:
	int data;
	binary_tree *left;
	binary_tree *right;

	binary_tree(int data)
	{
		this->data = data;
		left = right = nullptr;
	}
};

void linked_list_to_binary_tree(binary_tree **root, linked_list *l)
{
	queue<binary_tree *> bt;
	if(l == nullptr)
	{
		return;
	}

	*root = new binary_tree(l->data);
	bt.push(*root);
	l = l->next;
	
	while(l)
	{
		binary_tree *temp = bt.front();
		bt.pop();

		binary_tree *lefttree = nullptr, *righttree = nullptr;
		lefttree = new binary_tree(l->data);
		q.push(lefttree);
		l = l->next;
		if(l != nullptr)
		{
			righttree = new binary_tree(l->data);
			q.push(righttree);
			l = l->next;
		}
		temp ->left = lefttree;
		temp ->righ t= righttree;
	}
}