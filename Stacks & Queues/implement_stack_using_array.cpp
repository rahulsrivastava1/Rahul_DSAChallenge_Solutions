// implement a stack using array

#include<bits/stdc++.h>
using namespace std;
#define MAX 1000
class Stack
{
	int top;
	public:
		int st[MAX];
		Stack()
		{
			top=-1;
		}
		bool push(int x);
		int pop();
		int peek();
		bool isEmpty();
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
		cout<<"pushed!\n";
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
int Stack::peek()
{
	int y;
	if(top<0)
	{
		cout<<"Stack is empty!";
		return 0;
	}
	else
	{
		y=st[top];
		return y;
	}
}
bool Stack::isEmpty()
{
	return (top<0);
}
int main()
{
	class Stack s;
	s.push(10);
	s.push(20);
	s.push(30);
	s.push(40);
	s.push(50);
	cout<<"element popped from stack :"<<s.pop();
	cout<<"\nElements present in stack :";
	while(!s.isEmpty())
	{
		cout<<s.peek()<<" ";
		s.pop();
	}
	return 0;
}
