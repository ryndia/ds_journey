#include <iostream>
#include <queue>

using namespace std;

void showpq(priority_queue <int> pq)
{
	while(!pq.empty())
	{
		cout<<pq.top()<<endl;
		pq.pop();
	}
}

void showpqMin(priority_queue <int> pq)
{
	while(!pq.empty())
	{
		cout<<-pq.top()<<endl;
		pq.pop();
	}
}

int main()
{
	priority_queue <int> pq;
	priority_queue <int> minpq;

	pq.push(12);
	pq.push(11);
	pq.push(3);
	pq.push(45);
	pq.push(23);
	showpq(pq);

	minpq.push(-12);
	minpq.push(-11);
	minpq.push(-3);
	minpq.push(-45);
	minpq.push(-23);
	showpqMin(minpq);

	return 0;
}
