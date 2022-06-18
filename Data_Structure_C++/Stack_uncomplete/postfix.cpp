#include <iostream>
#include<bits/stdc++.h> 
#include <string.h>

using namespace std;

int level(char c)
{
	if(c =='^'){return 3;}
	else if(c == '*' || c=='/'){return 2;}
	else if(c = '+'|| c=='-'){return 1;}
	else{return 0;}
}

void InfixtoPostfix(string equation)
{
	stack<char> symbol;
	string output;

	for(char s: equation)
	{
		if((s>='a' && s<='z')||(s>= 'A' && s<= 'Z'))
		{
			output+=s;
		}
		else if(s == '(')
		{
			symbol.push(s);
		}
		else if(s ==')')
		{
			while(!symbol.empty()&& symbol.top()!='(')
			{
				output+=symbol.top();
				symbol.pop();
			}
			if(!symbol.empty() && symbol.top()=='(')
			{
				symbol.pop();
			}
		}
		else
		{	
			if(!symbol.empty()&& symbol.top()!= '(')
			{
				if(level(symbol.top())<level(s))
				{
					symbol.push(s);
				}
				else
				{
					while(!symbol.empty() &&symbol.top()!= '(' && level(symbol.top())>=level(s))
						{
							output+=symbol.top();
							symbol.pop();
						}
						if(!symbol.empty() &&symbol.top()!= '(')
						{
							symbol.pop();
						}
					symbol.push(s);
				}
			}
			else
			{
				symbol.push(s);
			}
		}
	}
	while(!symbol.empty())
	{
		output+=symbol.top();
		symbol.pop();
	}
	cout<<output<<endl;
}
/*
int main()
{
	InfixtoPostfix("(A+B)*(C-D)");
	return 0;
}*/

