// infix to prefix & postfix

#include<bits/stdc++.h>
using namespace std;
bool isOperator(char c)
{
	return (!isalpha(c) && !isdigit(c));
}
int getPriority(char c)
{
	if(c=='-' || c=='+')
		return 1;
	else if(c=='*' || c=='/')
		return 2;
	else if(c=='^')
		return 3;
	return 0;
}
string infixToPostfix(string input)
{
	input='('+input+')';
	int len=input.size();
	stack<char> st;
	string output;
	for(int i=0;i<len;i++)
	{
		if(isalpha(input[i]) || isdigit(input[i]))
			output +=input[i];
		else if(input[i]=='(')
			st.push('(');
		else if(input[i]==')')
		{
			while(st.top()!='(')
			{
				output +=st.top();
				st.pop();
			}
			st.pop();
		}
		else
		{
			if(isOperator(st.top()))
			{
				if(input[i]=='^')
				{
					while(getPriority(input[i])<=getPriority(st.top()))
					{
						output +=st.top();
						st.pop();
					}
				}
				else
				{
					while(getPriority(input[i])<getPriority(st.top()))
					{
						output +=st.top();
						st.pop();
					}
				}
				st.push(input[i]);
			}
		}
	}
	return output;
}
string infixToPrefix(string input)
{
	int len=input.size();
	reverse(input.begin(),input.end());
	for(int i=0;i<len;i++)
	{
		if(input[i]=='(')
		{
			input[i]=')';
			i++;
		}
		else if(input[i]==')')
		{
			input[i]='(';
			i++;
		}
	}
	string output=infixToPostfix(input);
	reverse(output.begin(),output.end());
	return output;
}
int main()
{
	string s = ("x+y*z/w+u");
    cout <<"Prefix :"<<infixToPrefix(s) <<endl;
    cout <<"Postfix :"<<infixToPostfix(s) <<endl;
	return 0;
}

