// implement a queue using array

#include<bits/stdc++.h>
using namespace std;
#define size 10
int rear=-1,front=-1,queu[size];
void add()
{
	int val;
	if(rear==size-1)
		cout<<"\nOverflow!";
	else
	{
		if(front=-1 && rear==-1)
		{
			front=0;
			rear=0;
			cout<<"\nEnter the value to push:";
			cin>>val;
			queu[rear]=val;
			cout<<"\nInserted!";
		}
		else
		{
			cout<<"\nEnter the value to push:";
			cin>>val;
			rear=rear+1;
			queu[rear]=val;
			cout<<"\nInserted!";
		}
	}
}
void remove()
{
	if(front==-1 && rear==-1)
		cout<<"\nUnderflow!";
	else
	{
		cout<<"\nDeleted value is:"<<queu[front];
		front = front+1;
	}
}
void display()
{
	int i;
	if(front==-1 && rear==-1)
		cout<<"\nQueue is empty.";
	else
	{
		for(i=front;i<=rear;i++)
		{
			cout<<queu[i]<<" ";
		}
	}
}
int main()
{
	int ch;
	while(1)
	{
		cout<<"\n** QUEUE MENU **";
		cout<<"\n 1.add 2.delete 3.display 4.exit";
		cout<<"\n Enter your choice(1-4):";
		cin>>ch;
		switch(ch)
		{
			case 1:
				add();
				break;
			case 2:
				remove();
				break;
			case 3:
				display();
				break;
			case 4:
				exit(0);
				break;
			default:
				cout<<"\nEnter correct choice!";
				break;
		}
	}
	return 0;
}
