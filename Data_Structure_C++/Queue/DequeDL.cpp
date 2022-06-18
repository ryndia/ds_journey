#include <iostream>

using namespace std;

class Deque
{
public:
	int data;
	int size = 0;
	Deque *next;
	Deque *previous;
	Deque *last;

	Deque(int d)
	{
		this->data = d;
		size++;
		next = nullptr;
		previous = nullptr;
		last = nullptr;
	}
};

void setlast(Deque **dq)
{
	(*dq)->last = (*dq);
	return;
}

void frontpush(Deque **dq, int d)
{
	Deque *temp = new Deque(d);
	if(*dq == nullptr)
	{
		*dq = temp;

		setlast(&(*dq));
		return;
	}
	temp->last = (*dq)->last;
	temp->next = *dq;
	(*dq)->previous = temp;
	*dq = temp;
	(*dq)->size++;
	return;
}

void enQueue(Deque **dq, int d)
{
	Deque *temp = new Deque(d);
	if(*dq == nullptr)
	{
		*dq = temp;
		setlast(&(*dq));
		return;
	}
	(*dq)->last->next = temp;
	temp->previous = (*dq)->last;
	(*dq)->last = temp;
	(*dq)->size++;
	return;
}

int deletefront(Deque **dq)
{
	if(*dq == nullptr){return 0;}
	Deque *temp = *dq;
	temp->last = (*dq)->last;
	*dq = temp->next;
	int d = temp->data;
	delete temp;
	(*dq)->size--;
	return d;
}

int deleterear(Deque **dq)
{
	if(*dq == nullptr){return 0;}
	Deque *temp = *dq;
	temp = temp->last;
	(*dq)->last = temp->previous;
	int d = temp->data;
	delete temp;
	(*dq)->size--;
	return d;
}

int peek(Deque *pq){return pq->data;}

int rear(Deque *pq){return pq->last->data;}

bool isempty(Deque *pq){ return (pq == nullptr)?:1,0;}

void erase(Deque **pq)
{
	Deque *temp = nullptr;
	*pq = temp;
	return;
}
void display(Deque *dq){
	while(dq != nullptr)
	{
		cout<<dq->data<<" ";
		dq = dq->next;
	}
	cout<<endl;
	return;
}

int main()
{
	Deque *dq = new Deque(1);
	setlast(&dq);
	frontpush(&dq,3);
	enQueue(&dq,6);	
	cout<<rear(dq)<<endl;
	cout<<peek(dq)<<endl;
	deletefront(&dq);
	cout<<rear(dq)<<endl;
	cout<<peek(dq)<<endl;
	frontpush(&dq,32);
	enQueue(&dq,45);	
	cout<<rear(dq)<<endl;
	cout<<peek(dq)<<endl;
	display(dq);
	return 0;
}
