// implement stack using queue

#include<bits/stdc++.h>
using namespace std;
class Stack
{
	queue<int> q1,q2;
	int curr_size;
	public:
		Stack()
		{
			curr_size=0;	
		}	
		void push(int x)
		{
			curr_size++;
			q2.push(x);
			while(!q1.empty())
			{
				q2.push(q1.front());
				q1.pop();
			}
			queue<int> q=q1;
			q1=q2;
			q2=q;
		}
		void pop()
		{
			if(q1.empty())
				return;
			q1.pop();
			curr_size--;
		}
		int top()
		{
			if(q1.empty())
				return -1;
			return q1.front();
		}
		int size()
		{
			return curr_size;
		}
};
int main()
{
    stack<int> st;
    st.push(1);
    st.push(2);
    st.push(3);
    cout <<"current size: "<<st.size()<<endl;
    cout<<st.top()<<endl;
    st.pop();
    cout<<st.top()<<endl;
    st.pop();
    cout<<st.top()<<endl;
    cout<<"current size: "<< st.size()<<endl;
    return 0;
}
