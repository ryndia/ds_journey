#include <iostream>
#include <bits/stdc++.h>

using namespace std;

//Left_Child_Right_Sibling

class node
{
public:
	int data;
	node *child;
	node *sibling;

	node(int data)
	{
		this->data = data;
		child = nullptr;
		sibing = nullptr;
	}
};

void addsibling(node **root,int data)
{
	node *temp = new node(data);
	if((*root)->sibing == nullptr)
	{
		(*root)->sibing = temp;
		return;
	}
	node *head = *root;
	while(head->sibing != nullptr)
	{
		head = head->sibing;
	}
	head->sibing = temp;
	return;
}

void addchild(node **root,int data)
{
	if(*root == nullptr){
		return;
	}
	if((*root)->child != nullptr)
	{
		addsibling(&(*root->child),data);
		return;
	}
	else
	{
		node *temp = new node(data);
		(*root)->child = temp;
		return;
	}
}

void traversal(node *root)
{
	if(root == nullptr)
	{
		return;
	}
	if(root->child != nullptr){
		traversal(root->child);
	}
	while(root != nullptr)
	{
		cout<<root->data<<" ";
		root = root->sibing;
	}
	return;
}