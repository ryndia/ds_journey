#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void nge(int arr[],int n)
{
	stack <int> num;
	int count = 0;

	num.push(arr[0]);

	for(int i = 1; i< n; i++)
	{
		if(num.empty())
		{
			num.push(arr[i]);
			continue;
		}

		while(!num.empty() && arr[i]> num.top())
		{
			cout<<num.top()<<"-->"<<arr[i]<<endl;
			num.pop();
			count++;
		}
		num.push(arr[i]);

	}
	while(!num.empty())
	{
		cout<<num.top()<<"--> -1"<<endl;
		num.pop();
	}
	cout<<count<<endl;
	return;
}

int main()
{
	int arr[] = {2,6,1,3,7};
	nge(arr,(sizeof(arr)/sizeof(arr[0])));
	return 0;
}