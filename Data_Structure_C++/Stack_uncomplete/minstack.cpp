#include <iostream>
#include <bits/stdc++.h> 

using namespace std;

class stackMin
{
public:
	stack <int> s;
	int minelement;

	void peek()
	{
		if(s.empty())
		{
			cout<<"empty"<<endl;
			return;
		}

		int temp = s.top();
		if(temp< minelement)
		{
			cout<<"element : "<<(2*minelement-temp);
		}
		else
		{
			cout<<"element : "<< temp;
		}
	}

	void push(int x)
	{
		if(s.empty())
		{
			s.push(x);
			minelement = x;
		}
		else
		{
			if(x<minelement)
			{
				s.push((2*x)- minelement);
				minelement = x;
			}
			else
			{
				s.push(x);
			}
		}
		return;
	}

	void pop()
	{
		if(s.empty())
		{
			cout<<"empty"<<endl;
			return;
		}
		int temp = s.top();
		s.pop();

		if(temp< minelement)
		{
			cout<<"element removed: "<<(minelement)<<endl;
			minelement=2*minelement-temp;
		}
		else
		{
			cout<<"element removed: "<< temp<<endl;
		}
	}

	void getMin()
	{
		if(s.empty())
		{
			cout<<"empty"<<endl;
			return;
		}
		cout<<"min element: "<<minelement<<endl;
	}
	
};

int main()
{
	stackMin s;
	s.push(420);
	s.push(12);
	s.push(2);
	s.push(4);
	s.getMin();
	s.pop();
	s.pop();
}