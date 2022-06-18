#include <iostream>
#include <bits/stdc++.h>

using namespace std;

queue<int> interleaving(queue<int> q)
{
	queue<int> temp = q;
	
	int i = 1;
	
	while(!temp.empty())
	{
		i++;
		temp.pop();
	}

	stack <int>s;
	
	for(int j = 1; j<=i/2; j++)
	{
		s.push(q.front());
		q.pop();
	}
	for(int j = 1; j<=i/2;j++)
	{
		q.push(s.top());
		s.pop();
	}
	for(int j = 1; j<=i/2; j++)
	{
		s.push(q.front());
		q.pop();
	}

	for(int j = 1;j<=i/2;j++)
	{
		q.push(s.top());
		s.pop();
		q.push(q.front());
		q.pop();
	}
	for(int j = 1;j<=i;j++)
	{
		s.push(q.front());
		q.pop();
	}
	for(int j = 1;j<=i;j++)
	{
		q.push(s.top());
		s.pop();
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
	for(int i = 0;i<100;i++){
		q.push(i);
	}
	q = interleaving(q);
	display(q);
	return 0;
}