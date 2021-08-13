// priority queue

#include<bits/stdc++.h>
#define MAX 5
int rear=-1,front=-1,queue[MAX],priorQueue[MAX];
void enqueue()
{
	if(front==0 && rear==MAX-1)
		cout<<"\nOVERFLOW!";
	else
	{
		int val,pri,i;
		cout<<"\nEnter value to push:";
		cin>>val;
		cout<<"\nEnter priority value:";
		cin>>pri;
		if(front==-1)
		{
			front=0;
			rear=0;
			queue[rear]=val;
			priorQueue[rear]=pri;
			cout<<"\nValue and priority inserted!";
		}
		else if(rear==MAX-1)
		{
			for(i=front;i<=rear;i++)
			{
				queue[i-front]=queue[i];
				priorQueue[i-front]=priorQueue[i];
				rear=rear-front;
				front=0;
				for(i=rear;i>front;i--)
				{
					if(pri>priorQueue[i])
					{
						queue[i+1]=queue[i];
						priorQueue[i+1]=priorQueue[i];
					}
					else
					{
						break;
					}
					queue[i+1]=val;
					priorQueue[i+1]=pri;
					rear++;
				}
			}
				cout<<"\nValue and Priority inserted!";
		}
		else
		{
			for(i=rear;i>=front;i--)
			{
				if(pri>priorQueue[i])
				{
					queue[i+1]=queue[i];
					priorQueue[i+1]=priorQueue[i];
				}
				else
					break;
				queue[i+1]=val;
				priorQueue[i+1]=pri;
				rear++;
				cout<<"\nvalue and priority inserted";
			}
		}
	}
}
void dequeue()
{
	if(front==-1)
		cout<<"\nUNDERFLOW!";
	else
	{
		printf("\nDeleted value is %d\t priority=%d",queue[front],priorQueue[front]);
		if(front==rear)
		{
			front=-1;
			rear=-1;
		}
		else
			front++;
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
			printf("\nElement=%d\t Priority=%d",queue[i],priorQueue[i]);
		}
	}
}
int main()
{
	int ch;
	while(1)
	{
		cout<<"\n**PRIORITY QUEUE MENU **";
		cout<<"\n 1.add 2.delete 3.display 4.exit";
		cout<<"\n Enter your choice(1-4):";
		cin>>ch;
		switch(ch)
		{
			case 1:
				enqueue();
				break;
			case 2:
				dequeue();
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
