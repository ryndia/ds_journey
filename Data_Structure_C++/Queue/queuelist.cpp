#include <iostream>

using namespace std;

class Queue
{
public:
	int data;
	Queue *next;

	Queue(int x)
	{
		data = x;
		next = nullptr;
	}
};

void insert(Queue **head, int data)
{
	Queue *temp = new Queue(data);
	Queue *h = *head;

	if(temp == nullptr)
	{
		*head = temp;
		return;
	}
	else
	{
		while(h->next != nullptr)
		{
			h= h->next;
		}
		h->next = temp;
		return;
	}
}

void printQ(Queue *head)
{
	while(head != nullptr)
	{
		cout<<head->data<<endl;
		head = head->next;
	}
	return;
}

int deQueue(Queue **head)
{
	if(*head == nullptr)
	{
		cout<<"empty"<<endl;
		return 0;
	}
	else
	{
		Queue *temp = *head;
		*head = temp->next;
		int x = temp->data;
		delete temp;
		return x;
	}
}



int main()
{
	Queue *q = new Queue(4);
	insert(&q, 2);
	printQ(q);
	cout<<deQueue(&q);
}