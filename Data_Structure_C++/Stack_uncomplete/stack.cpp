#include <iostream>

using namespace std;
/*
class stack
{
public:
	int data;
	stack* next;

	stack(int data)
	{
		this->data = data;
		this->next = nullptr;
	}
};

void push(stack **head,int data)
{
	stack *rootref = *head;
	stack *temp = new stack(data);
	if(temp == nullptr)
	{
		*head = temp;
		return;
	}
	else
	{
		temp->next = rootref;
		*head = temp;
		return;
	}
}

int Isempty(stack * head)
{
	return !head;
}

void peek(stack *head)
{
	if(Isempty(head)!= 1)
	{
		cout<<head->data;
	}
	else
	{
		cout<<"empty"<<endl;
	}
}

void pop(stack **head)
{
	if(Isempty(*head)!= 1)
	{
		stack *temp = *head;
		temp = temp->next;
		delete *head;
		*head = temp;
	}
	else
	{
		cout<<"empty"<<endl;
	}
}

void printstack(stack *head)
{
	while(head!= nullptr)
	{
		cout<<head->data<<endl;
		head = head ->next;
	}
	return;
}

int main()
{
	stack *root = nullptr;
	push(&root,10);
	push(&root,20);
	push(&root,30);
	printstack(root);
	pop(&root);
	printstack(root);
	return 0;
}
*/
//two stack in one stack

class stack
{
	int * arr;
	int size;
	int top1, top2;

public:

	stack(int n)
	{
		size= n;
		arr = new int[n];
		top1 = -1;
		top2 = size;
	}

	void push1(int x)
	{
		if(top1<(top2-1))
		{
			top1++;
			arr[top1]= x;
		}
		else
		{
			cout<<"stack overflow"<<endl;
			return;
		}
		return;
	}

	void push2(int x)
	{
		if(top1<(top2-1))
		{
			top2--;
			arr[top2] = x;
		}
		else
		{
			cout<<"stack overflow"<<endl;
			return;
		}
		return;
	}

	int pop1()
	{
		if(top1>= 0)
		{
			int x = arr[top1];
			top1--;
			return x;
		}
		else
		{
			cout<<"stack underflow"<<endl;
			return -1;
		}
	}

	int pop2()
	{
		if(top2<size)
		{
			int x = arr[top2];
			top2++;
			return x;
		}
		else
		{
			cout<<"stack underflow"<<endl;
			return -1;
		}
	}

};

int main()
{
	stack ts(4);

	ts.push1(2);
	ts.push1(1);
	ts.push1(1);
	ts.push2(0);
	ts.push2(3);
	return 0;
}