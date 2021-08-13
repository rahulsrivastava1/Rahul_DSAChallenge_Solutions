// implement queue using Linked List

#include<bits/stdc++.h>
using namespace std;
struct node
{
	int data;
	struct node *next;
};
struct node *front,*rear;
void add()
{
	struct node *ptr;
	ptr=(struct node *)malloc(sizeof(struct node));
	int val;
	cout<<"\nEnter the value to push:";
	cin>>val;
	ptr->data=val;
	if(front==NULL)
	{
		front=rear=ptr;
		front->next=rear->next=NULL;
		cout<<"\nValue inserted.";
	}
	else
	{
		rear->next=ptr;
		rear=ptr;
		rear->next=NULL;
		cout<<"\nInserted.";
	}
}
void remove()
{
	struct node *ptr;
	if(front==NULL)
		cout<<"\nUnderflow";
	else
	{
		ptr=front;
		cout<<"\nDeleted value :"<<ptr->data;
		front=front->next;
		free(ptr);
	}
}
void display()
{
	struct node *ptr;
	ptr=front;
	if(front==NULL)
		cout<<"\nQueue is empty.";
	else
	{
		cout<<"\nprinting values is:";
		while(ptr!=NULL)
		{
			cout<<ptr->data<<" ";
			ptr=ptr->next;
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
