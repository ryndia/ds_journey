#include <iostream>
#include<bits/stdc++.h> 
#include <string.h>

using namespace std;

string convertor(string postfix)
{

	stack <string> output;

	for(char c :postfix)
	{
		if((c>='a' && c<='z') || (c>='A' && c<='Z'))
		{
			string s = "";
			s+=c;
			output.push(s);
			s="";
		}
		else if(c =='^'||c =='*'||c =='/'||c =='-'||c =='+')
		{
			string temp = output.top();
			output.pop();
			string temp1 = output.top();
			output.pop();
			temp1 = "("+temp + c+temp1+")";
			output.push(temp1);
		}
	}

	return output.top();
}

int main()
{
	convertor("abc++");
	return 0;
}