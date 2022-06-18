#include <iostream>
#include <bits/stdc++.h>

using namespace std;

queue <int> reverseK(queue<int> q, int k)
{
	stack <int> s;
	int i = 0;
	while(i<k)
	{
		s.push(q.front());
		q.pop();
		i++;
	}
	queue<int> q2;
	while(!q.empty() || !s.empty())
	{
		if(!s.empty())
		{
			q2.push(s.top());
			s.pop();
		}
		else
		{
			q2.push(q.front());
			q.pop();
		}
	}
	return q2;
}

void display(queue<int> q)
{
	while(!q.empty())
	{
		cout<<q.front()<<" ";
		q.pop();
	}
	cout<<endl;
	return;
}

int main()
{
	queue <int> q;
	q.push(1);
	q.push(2);
	q.push(3);
	q.push(4);
	q.push(5);
	q = reverseK(q,2);
	display(q);
	return 0;
}