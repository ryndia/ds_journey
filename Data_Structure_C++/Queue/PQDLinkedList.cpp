#include <iostream>

using namespace std;

class Priority_Queue
{
public:
	int data;
	int priority;
	Priority_Queue *next;
	Priority_Queue *previous;

	Priority_Queue(int d,int p)
	{
		this->data = d;
		this->priority = p;
		next = nullptr;
		previous = nullptr;
	}
};

void insert(Priority_Queue **pq, int d, int p)
{
	Priority_Queue *temp = new Priority_Queue(d,p);

	if(*pq == nullptr)
	{
		*pq = temp;
		return;
	}
	Priority_Queue *head = *pq;

	if(head->priority < p)
	{
		temp->next == head;
		head->previous = temp;
		*pq = temp;
		return;
	}

	while(head->next != nullptr && head->priority >= p)
	{
		head = head->next;
	}
	if(head->priority < p)
	{
		temp->next = head;
		temp->previous = head->previous;
		head->previous->next = temp;
		return;
	}
	else
	{
		head->next = temp;
		temp->previous = head;
		return;
	}
}

void display(Priority_Queue *pq)
{
	while(pq!= nullptr)
	{
		cout<<pq->data<<" "<<pq->priority<<" ";
		pq = pq->next;
	}
	cout<<endl;
	return;
}

int peek(Priority_Queue *pq){return pq->data;}

bool isempty(Priority_Queue *pq){return (pq == nullptr)?:1,0;}

int pop(Priority_Queue **pq)
{
	Priority_Queue *temp = *pq;
	*pq = temp->next;
	(*pq)->previous = nullptr;
	int d = temp->data;
	delete temp;
	return d;
}

int main()
{
	Priority_Queue *pq = new Priority_Queue(1,2);
	cout<<isempty(pq)<<endl;
	insert(&pq,3,4);
	insert(&pq,5,3);
	insert(&pq,6,4);
	insert(&pq,7,1);
	display(pq);
	cout<<pop(&pq)<<endl;
	return 0;
}