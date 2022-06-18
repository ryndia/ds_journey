#include <iostream>

using namespace std;

class Priority_Queue
{
public:
	int data;
	int priority;
	Priority_Queue *next;

	Priority_Queue(int d,int p)
	{
		data = d;
		priority = p;
	}
};

void insert(Priority_Queue **pq, int d, int p)
{
	Priority_Queue *head = *pq;
	Priority_Queue *temp = new Priority_Queue(d,p);
	if(head == nullptr)
	{
		*pq = temp;
		return;
	}
	if(head->priority < p)
	{
		temp->next = head;
		*pq = temp;
		return;
	}
	Priority_Queue *previous = nullptr;
	while(head->next != nullptr && head->priority>=p)
	{
		previous = head;
		head = head->next;
	}
	if(head->priority < p)
	{
		temp->next = head;
		previous->next = temp;
		return;
	}
	else
	{
		head->next = temp;
		return;
	}
}

void display(Priority_Queue *pq)
{
	while(pq != nullptr)
	{
		cout<<pq->data<<" "<<pq->priority<<" ";
		pq = pq->next;
	}
	cout<<endl;
}

int pop(Priority_Queue **pq)
{
	Priority_Queue *temp = *pq;
	*pq = temp->next;
	int d = temp->data;
	delete temp;
	return d;
}

int peek(Priority_Queue *pq){return pq->data;}

bool isempty(Priority_Queue *pq){return (pq == nullptr)?:1,0;}

int main()
{
	Priority_Queue *pq = new Priority_Queue(1,2);
	cout<<isempty(pq)<<endl;
	insert(&pq,3,4);
	insert(&pq,5,3);
	insert(&pq,6,4);
	insert(&pq,7,1);
	display(pq);
	cout<<pop(&pq)<<endl;nn
	return 0;
}