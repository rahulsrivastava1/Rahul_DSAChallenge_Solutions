// reverse a queue

#include<bits/stdc++.h>
using namespace std;
void print(queue<int>& q)
{
	while(!q.empty())
	{
		cout<<q.front()<<" ";
		q.pop();
	}
}
void reverseQueue(queue<int>& q)
{
	stack<int> st;
	while(!q.empty())
	{
		st.push(q.front());
		q.pop();
	}
	while(!st.empty())
	{
		q.push(st.top());
		st.pop();
	}
}
int main()
{
	queue<int> Queue;
    Queue.push(10);
    Queue.push(20);
    Queue.push(30);
    Queue.push(40);
    Queue.push(50);
    Queue.push(60);
    Queue.push(70);
    Queue.push(80);
    Queue.push(90);
    Queue.push(100);
  	cout<<"Original queue:";
  	cout<<10<<" "<<20<<" "<<30<<" "<<40<<" "<<50<<" "<<60<<" "<<70<<" "<<80<<" "<<90<<" "<<100;
    reverseQueue(Queue);
    cout<<"\nReversed queue:";
    print(Queue);
    return 0;
}
