#include <iostream>

using namespace std;

class DLL
{
public:
	int data;
	DLL *next;
	DLL *prev;

	DLL(int x)
	{
		data = x;
		prev = next = nullptr;
	}
};

class stack
{
public:
	DLL *head;
	DLL *middleVlue;
	DLL *last;
	int s_size;

	stack(int x)
	{
		head = new DLL(x);
		last = head;
		middleVlue = nullptr;
		s_size = 1;
	}

	stack()
	{
		head = nullptr;
		middleVlue = nullptr;
		last = nullptr;
		s_size = 1;
	}

	void push(int x)
	{
		++s_size;
		DLL *temp = new DLL(x);
		if(head == nullptr)
		{
			head = temp;
			last = head;
			middleVlue = head;
			return;
		}

		temp->next = head;
		head->prev = temp;
		head = temp;

		if(s_size%2!=0)
		{
			middleVlue=middleVlue->prev;
		}
	}

	void pop()
	{
		s_size= s_size-1;
		if(head == nullptr){cout<<"empty stack"<<endl;return;}

		DLL *temp = head->next;
		delete head;
		head = temp;
		if(s_size%2== 0){middleVlue = middleVlue->next;}
		return;
	}

	void printstack()
	{
		DLL * temp = head;
		while(temp!= nullptr)
		{
			cout<<temp->data<<" ";
			temp = temp->next;
		}
		cout<<endl;
		return;
	}

	void middle()
	{
		cout<<middleVlue->data<<endl;
	}

	void DeleteMiddle()
	{	
		s_size= s_size-1;
		DLL *temp = nullptr;
		if(s_size%2== 0)
		{
			temp = middleVlue->next;
		}
		else{
			temp = middleVlue->prev;
			}

		middleVlue->prev->next = middleVlue->next;
		middleVlue->next->prev = middleVlue->prev;
		delete middleVlue;
		middleVlue= temp;
		return;
	}

	void getlast()
	{
		cout<<last->data<<endl;
	}

	void RemovelastElement()
	{
		DLL *temp = last->prev;
		last->prev->next = nullptr;
		delete last;
		last = temp;
		return;
	}
};

stack merge(stack s1, stack s2)
{
	stack s3;
	if(s1.last->next== nullptr && s2.head!= nullptr)
	{
		s1.last->next = s2.head;
		s3 = s1;
		return s3;
	}
	exit(0);
}


int main()
{
	stack s;
	s.pop();
	s.push(1);
	s.push(2);
	s.push(3);
	s.push(4);
	s.push(5);
	s.printstack();

	stack s1;
	s1.push(10);
	s1.push(25);
	s1.push(38);
	s1.push(47);
	s1.printstack();

	stack s3 = merge(s,s1);
	s3.printstack();
	//s.middle();
	//s.pop();
	//s.printstack();
	//s.middle();
	//s.DeleteMiddle();
	//s.middle();
	s.getlast();
	s.RemovelastElement();
	s.getlast();


	return 0;
}