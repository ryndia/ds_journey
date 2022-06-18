#include <iostream>
#include<bits/stdc++.h> 
#include <string.h>

using namespace std;

bool checkopposite(char stackchar,char c)
{
	if(stackchar==c)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void checkBalance(string s)
{
	stack<char> output;

	for(char c:s)
	{
		if(output.empty())
		{
			output.push(c);
		}
		else
		{
			if(checkopposite(output.top(),c)==true)
			{
				output.pop();
			}
			else
			{
				output.push(c);
			}
		}
	}
	if(output.empty())
	{
		cout<<"balanced"<<endl;
	}
	else
	{
		cout<<"unbalanced"<<endl;
	}
	return;
}

int main()
{
	checkBalance("{[}]");
	return 0;
}