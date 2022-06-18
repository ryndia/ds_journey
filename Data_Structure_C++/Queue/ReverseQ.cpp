#include <iostream>
#include <bits/stdc++.h>

using namespace std;

queue<int> reverser(queue <int> q)
{
	stack<int> temp;
	while(!q.empty())
	{
		temp.push(q.front());
		q.pop();
	}

	while(!temp.empty())
	{
		q.push(temp.top());
		temp.pop();
	}
	return q;
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
	q = reverser(q);
	display(q);
	return 0;
}