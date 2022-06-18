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

void InfixtoPrefix(string infix)
{
	stack<char> symbol;
	string output;

	string equation = "";
	int l =infix.length();

	for(int i = 0; i< l;i++)
	{
		equation+=infix[l-i-1];
		cout<<i<<endl;
	}
	 cout<<equation<<endl;
	for(char s: equation)
	{
		if((s>='a' && s<='z')||(s>= 'A' && s<= 'Z'))
		{
			output=s+output;
		}
		else if(s == ')')
		{
			symbol.push(s);
		}
		else if(s =='(')
		{
			while(!symbol.empty()&& symbol.top()!=')')
			{
				output=symbol.top()+output;
				symbol.pop();
			}
			if(!symbol.empty() && symbol.top()==')')
			{
				symbol.pop();
			}
		}
		else
		{	
			if(!symbol.empty()&& symbol.top()!= ')')
			{
				if(level(symbol.top())<=level(s))
				{
					symbol.push(s);
				}
				else
				{
					while(!symbol.empty() &&symbol.top()!= ')' && level(symbol.top())>level(s))
						{
							output=symbol.top()+output;
							symbol.pop();
						}
						if(!symbol.empty() &&symbol.top()== ')')
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
	cout<<output<<endl;
	while(!symbol.empty())
	{
		output=symbol.top()+output;
		symbol.pop();
	}
	cout<<output<<endl;
}

int main()
{
	InfixtoPrefix("(A-B/C)*(A/K-L)");
	return 0;
}