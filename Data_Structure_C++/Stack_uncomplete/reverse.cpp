#include <iostream>
#include <bits/stdc++.h>
using namespace std;

stack <int> reversed(stack <int> n, stack <int> r)
{
	if(n.empty())
	{
		return r;
	}
	else
	{
		r.push(n.top());
		n.pop();
		return reversed(n,r);
	}
}

int main()
{
	stack <int>	n;
	stack <int> r;
	n.push(3);
	n.push(2);
	n.push(1);
	n = reversed(n,r);
	while(!n.empty())
	{
		cout<<n.top();
		n.pop();
	}
}