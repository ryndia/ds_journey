#include <iostream>
#include<bits/stdc++.h> 
#include <string.h>

using namespace std;

string convertor(string prefix)
{
	string prefixReverse = "";
	int l =prefix.length();

	for(int i = 0; i< l;i++)
	{
		prefixReverse+=prefix[l-i-1];
	}

	stack <string> output;

	for(char c :prefixReverse)
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
			temp1 = "("+temp1 + c+temp+")";
			output.push(temp1);
		}
	}

	return output.top();
}
/*
int main()
{
	convertor("*-A/BC-/AKL");
	return 0;
}*/