// minimum and maximum element from stack

#include<bits/stdc++.h>
using namespace std;
void findMax(stack<int> s)
{
	int m=s.top();
	int a;
	while(!s.empty())
	{
		a=s.top();
		if(m<a)
			m=a;
		s.pop();
	}
	cout<<"Maximum element in stack is:"<<m<<endl;
}
void show(stack<int> s)
{
	while(!s.empty())
	{
		cout<<" "<<s.top();
		s.pop();
	}
	cout<<endl;
}
void findMin(stack<int> s)
{
	int m=s.top();
	int a;
	while(!s.empty())
	{
		a=s.top();
		if(m>a)
			m=a;
		s.pop();
	}
	cout<<"Minimum element in stack is:"<<m<<endl;
}
int main()
{
	stack<int> st;
	st.push(4);
    st.push(2);
    st.push(20);
    st.push(12);
    st.push(52);
    st.push(14);
    cout<<"The elements in stack are:";
    show(st);
    findMax(st);
    findMin(st);
    return 0;
}
