#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class binary_tree
{
public:
	int data;
	binary_tree *next;
	binary_tree *left;
	binary_tree *right;

	binary_tree(int data)
	{
		this->data = data;
		next = nullptr;
		left = nullptr;
		right = nullptr;
	}
};

void linktree(binary_tree **root)
{
	if(*root == nullptr)
	{
		return;
	}
	static binary_tree *p = nullptr;
	linktree(&((*root)->right));
	(*root)->next = p;
	p = *root;
	linktree(&((*root)->left));
}

int main()
{
	binary_tree *root = new binary_tree(3);
    root->left        = new binary_tree(4);
    root->right       = new binary_tree(4);
    root->left->left  = new binary_tree(1);
    root->left->right = new binary_tree(3);
    root->right->right = new binary_tree(5);
    root->right->left = new binary_tree(6);
    linktree(&root);
    binary_tree *ptr = root->left->left;
    while(ptr!= nullptr)
    {
    	cout<<ptr->data<<endl;
    	ptr=ptr->next;
    }
}
