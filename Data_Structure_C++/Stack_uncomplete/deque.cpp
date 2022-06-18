#include <iostream>

using namespace std;

class DLL
{
public:
	int data;
	DLL *next;
	DLL *prev;

	DLL(int data)
	{
		this->data = data;
		next = prev = nullptr;
	}
};

class deque
{
	DLL *head;
	DLL *last;
	int size;

public:
	deque()
	{
		head = nullptr;
		last = nullptr;
		size = 0;
	}

	deque(int x)
	{
		head = new DLL(x);
		last = new DLL(x);
		size = 0;
	}

	void s()
	{
		cout<<size<<endl;
	}

	void insert_first(int x)
	{
		size++;
		DLL * temp = new DLL(x);
		if(head == nullptr)
		{
			head = temp;
			last = temp;
			return;
		}

		temp->next = head;
		head ->prev = temp;
		head =temp;
		return;
	}

	void insert_last(int x)
	{
		size++;
		DLL * temp = new DLL(x);
		if(last == nullptr)
		{
			last = temp;
			head = temp;
			return;
		}

		last->next = temp;
		temp ->prev = last;
		last = temp;
		return;
	}

	void remove_first()
	{
		if(head == nullptr)
		{
			return;
		}

		size--;
		if(head->next== nullptr)
		{
			delete head;
			delete last;
			return;
		}

		DLL *temp = head->next;
		delete head;
		head = temp;
		return;
	}

	void remove_last()
	{
		if(last == nullptr)
		{
			return;
		}
		size--;

		if(last->prev== nullptr)
		{
			delete head;
			delete last;
			return;
		}

		DLL * temp = last->prev;
		delete last;
		last = temp;
		return;
	}

	bool isEmpty()
	{
		return head;
	}

	void display()
	{
		DLL *temp = head;
		while(temp!= nullptr)
		{
			cout<<temp->data<<" ";
			temp = temp->next;
		}
		cout<<endl;
	}

	void reverseDisplay()
	{
		DLL * temp = last;
		while(temp != nullptr)
		{
			cout<<temp->data<<" ";
			temp = temp->prev;
		}
		cout<<endl;
	}
};

class stack: public deque
{
public:
	void push(int x)
	{
		insert_last(x);
	}

	void pop()
	{
		remove_last();
	}

	void print()
	{
		reverseDisplay();
	}
};

class queue: public deque
{
public:
	void Enqueue(int x)
	{
		insert_first(x);
	}

	void Dequeue()
	{
		remove_first();
	}
	
	void print()
	{
		display();
	}
};


int main()
{
	stack s;
	s.push(0);
	s.push(1);
	s.push(2);
	s.push(3);
	//s.pop();
	s.print();
	s.s();

	queue q;
	q.Enqueue(3);
	q.Enqueue(4);
	q.Enqueue(5);
	q.Enqueue(6);
	//q.Dequeue();
	q.print();
	q.s();

	return 0;
}