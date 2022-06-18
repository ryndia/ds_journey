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

void convertor(string postfix)
{
	stack<string> output;

	for(int i = 0; i< postfix.length();i++)
	{
		if(check postfix[i])== false)
		{
			string s="";
			s+ postfix[i];
			output.push(s);
		}
		else
		{
			string temp = output.top();
			output.pop();
			string temp1 = output.top();
			output.pop();
			temp1 = postfix[i] + temp1 + temp;
			output.push(temp1);
		}		
	}
	cout<<output.top();
}

int main()
{
	convertor("AB+CD-*");
	return 0;
}
 