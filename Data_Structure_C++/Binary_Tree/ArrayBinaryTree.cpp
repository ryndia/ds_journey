#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class ArrayTree
{
public:
	int *Arr;
	int size;
	ArrayTree(int s)
	{
		arr = new int[s];
		size = s;
	}

	void insertleft(int key, int parent)
	{
		if(arr[0]== '\0')
		{
			arr[0]= key;
			return;
		}
		if(arr[parent] == '\0')
		{
			cout<<"invalid parent"<<endl;
			return;
		}
		else
		{
			arr[(parent *2 )+1] = key;
			return;
		}
	}

	void insertright(int key, int parent)
	{
		if(arr[0]== '\0')
		{
			arr[0]= key;
			return;
		}
		if(arr[parent] == '\0')
		{
			cout<<"invalid parent"<<endl;
			return;
		}
		else
		{
			arr[(parent *2 )+2] = key;
			return;
		}
	}

	void print()
	{
		for(int i = 0;i< size;i++)
		{
			cout<<arr[i]<<" ";
		}
		cout<<endl;
	}
};
