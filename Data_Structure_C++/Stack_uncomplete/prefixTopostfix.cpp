#include <iostream>
#include <string.h>
#include<bits/stdc++.h> 

using namespace std;

bool check(char c)
{
	if(c =='^'||c =='*'||c =='/'||c =='-'||c =='+')
	{
		return true;
	}
	else
	{
		return false;
	}
}

void convertor(string prefix)
{
	stack<string> output;

	for(int i = prefix.length()-1;i>=0;i--)
	{
		if(check(prefix[i])== false)
		{
			string s="";
			s+=prefix[i];
			output.push(s);
		}
		else
		{
			string temp = output.top();
			output.pop();
			string temp1 = output.top();
			output.pop();
			temp1 = temp + temp1+prefix[i];
			output.push(temp1);
		}		
	}
	cout<<output.top();
}

int main()
{
	convertor("*-A/BC-/AKL");
	return 0;
}
 