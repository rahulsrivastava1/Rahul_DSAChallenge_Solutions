// sort the elements in stack

#include<bits/stdc++.h>
using namespace std;
stack<int> sortStack(stack<int> &input)
{
	stack<int> tmpStack;
	while(!input.empty())
	{
		int temp=input.top();
		input.pop();
		while(!tmpStack.empty() && tmpStack.top()>temp)
		{
			input.push(tmpStack.top());
			tmpStack.pop();
		}
		tmpStack.push(temp);
	}
	return tmpStack;
}
int main()
{
	stack<int> st;
	st.push(34);
	st.push(3);
	st.push(31);
	st.push(98);
	st.push(93);
	st.push(23);
	stack<int> tmpStack=sortStack(st);
	cout<<"Sorted stack are:";
	while(!tmpStack.empty())
	{
		cout<<tmpStack.top()<<" ";
		tmpStack.pop();
	}
	return 0;
}
