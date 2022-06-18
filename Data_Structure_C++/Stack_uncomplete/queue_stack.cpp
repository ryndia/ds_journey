#include <bits/stdc++.h> 
#include <iostream>

using namespace std;

/*stack to implement queue
struct Queue{
	stack <int> s1, s2;

	void enqueue(int x)
	{
		while(!s1.empty())
		{
			s2.push(s1.top());
			s1.pop();
		}

		s1.push(x);

		while(!s2.empty())
		{
			s1.push(s2.top());
			s2.pop();
		}
	}

	int dequeue()
	{
		if(s1.empty())
		{
			cout<<"empty"<<endl;
			return -1;
		}
		else
		{
			int x = s1.top();
			s1.pop();
			return x;
		}
	}
};

struct Queue
{
	stack <int> s1, s2;

	void enqueue(int x){s1.push(x);}

	int dequeue()
	{
		if(s1.empty() && s2.empty())
		{
			cout<<"empty"<<endl;
			return -1;
		}

		if(s2.empty())
		{
			while(!s1.empty())
			{
				s2.push(s1.top());
				s1.pop();
			}
		}

		int x = s2.top();
		s2.pop();
		return x;
		}
};

int main()
{
	Queue root;
	root.enqueue(1);
	root.enqueue(2);
	root.enqueue(4);

	cout<<root.dequeue()<<endl;
	cout<<root.dequeue()<<endl;
	cout<<root.dequeue()<<endl;

	return 0;
}*/

/*queue to implement stack

class stackQ
{
	queue<int> q1,q2;
	int s_size;
public:
	stackQ()
	{
		s_size = 0;
	}

	void push(int x)
	{
		q1.push(x);
		s_size++;
	}

	void pop()
	{
		if(q1.empty())
		{
			return;
		}

		while(q1.size()!=1)
		{
			q2.push(q1.front());
			q1.pop();
		}

		q1.pop();
		s_size--;

		queue<int> q = q1;
		q1 = q2;
		q2 = q;
	}

	int top()
	{
		if(q1.empty())
		{
			return 0;
		}

		while(q1.size()!=1)
		{
			q2.push(q1.front());
			q1.pop();
		}

		int temp = q1.front();
		q1.pop();
		q2.push(temp);

		queue<int> q = q1;
		q1 = q2;
		q2 = q;
		return temp;
	}

	int size()
	{
		return s_size;
	}
};

int main()
{
	stackQ s;
	s.push(2);
	s.push(2);
	s.pop();
	cout<<s.size();
}*/

/* stack implement with one queue
class stackQ
{
	queue <int> q;
public:
	void push(int val)
	{
		q.push(val);
		int s = q.size();

		for(int i = 1; i<s;i++)
		{
			q.push(q.front());
			q.pop();
		}
		return;
	}

	void pop()
	{
		if(q.empty())
		{
			cout<<"empty"<<endl;
			return;
		}
		q.pop();
	}

	bool empty()
	{
		return q.empty();
	}

	int top()
	{
		return q.front();
	}

	void print()
	{
		queue<int> qcopy = q;
		while(!qcopy.empty())
		{
			cout<<qcopy.front()<<" ";
			qcopy.pop();
		}
		cout<<endl;
	}

};

int main()
{
	stackQ s;
	s.push(1);
	s.push(2);
	s.push(3);
	s.push(4);

	s.print();
	return 0;
}*/