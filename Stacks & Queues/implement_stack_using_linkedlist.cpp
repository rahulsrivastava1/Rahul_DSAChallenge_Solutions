// implement stack using LinkedList

#include<bits/stdc++.h>
using namespace std;
class StackNode
{
	public:
		int data;
		StackNode *next;	
};
StackNode *newNode(int x)
{
	StackNode *stackNode=new StackNode();
	stackNode->data=x;
	stackNode->next=NULL;
	return stackNode;
}
int isEmpty(StackNode *head)
{
	return !head;
}
void push(StackNode **head,int x)
{
	StackNode *stackNode=newNode(x);
	stackNode->next= *head;
	*head=stackNode;
	cout<<x<<"pushed to stack!\n";
}
int pop(StackNode **head)
{
	if(isEmpty(*head))
		return INT_MIN;
	StackNode *temp=*head;
	*head=(*head)->next;
	int popped=temp->data;
	free(temp);
	return popped;
}
int peek(StackNode *head)
{
	if(isEmpty(head))
		return INT_MIN;
	return head->data;
}
int main()
{
	StackNode *head=NULL;
	push(&head,10);
	push(&head,20);
	push(&head,30);
	push(&head,40);
	push(&head,50);
	cout<<"\npopped element from stack :"<<pop(&head);
	cout<<"\nTop element in stack :"<<peek(head);
	cout<<"\nElement present in stack:";
	while(!isEmpty(head))
	{
		cout<<peek(head)<<" ";
		pop(&head);
	}
	return 0;
}
