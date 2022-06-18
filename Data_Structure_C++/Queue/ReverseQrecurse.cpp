#include <iostream>
#include <bits/stdc++.h>

using namespace std;

queue<int>reverse(queue<int> q)
{
	if(q.empty())
	{
		return q;
	}
	else
	{
		int x = q.front();
		q.pop();
		q = reverse(q);
		q.push(x);
		return q;
	}
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
	q = reverse(q);
	display(q);
	return 0;
}