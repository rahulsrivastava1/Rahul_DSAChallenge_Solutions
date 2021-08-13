// an expression of brackets is valid or not

#include<bits/stdc++.h>
using namespace std;
#define MAX 1000
class Stack
{
	public:
		int top;
		int st[MAX];
		Stack()
		{
			top=-1;
		}
		bool push(int x);
		int pop();
};
bool Stack::push(int x)
{
	if(top>=MAX-1)
	{
		cout<<"Stack is overflow!";
		return false;
	}
	else
	{
		st[++top]=x;
		return true;
	}
}
int Stack::pop()
{
	int x;
	if(top<0)
	{
		cout<<"Stack is underflow!";
		return 0;
	}
	else
	{
		x=st[top--];
		return x;
	}
}
int main()
{
	class Stack s;
	char exp[MAX],temp;
	cout<<"Enter expression for check:";
	cin>>exp;
	int flag=1;
	for(int i=0;i<strlen(exp);i++)
	{
		if(exp[i]=='(' || exp[i]=='{' || exp[i]=='[')
			s.push(exp[i]);
		if(exp[i]==')' || exp[i]=='}' || exp[i]==']')
			if(s.top==-1)
				flag=0;
			else
			{
				temp=s.pop();
				if(exp[i]==')' && (temp=='{' || temp=='['))
					flag=0;
				if(exp[i]=='}' && (temp=='(' || temp=='['))
					flag=0;
				if(exp[i]==']' && (temp=='{' || temp=='('))
					flag=0;
			}
	}
	if(s.top>=0)
		flag=0;
	if(flag==1)
		printf("Valid expression.");
	else
		printf("Invalid expression.");
	return 0;
}
