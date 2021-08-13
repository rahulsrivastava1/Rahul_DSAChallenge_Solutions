// merge and split

#include<bits/stdc++.h>
using namespace std;
struct node
{
	int data;
	struct node *next;
};
struct node *head1=NULL;
struct node *head2=NULL;
void push(node ** head_ref, int new_data)
{
    node* new_node = new node();
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}
void printLinkedlist(struct node *head)
{
	struct node *temp=head;
	while(temp!=NULL)
	{
		cout<<temp->data<<" ";
		temp=temp->next;
	}
}
struct node* alternateMerge(struct node *head1,struct node *head2)
{
	struct node temp;
	struct node *ptr=&temp;
	temp.next=NULL;
	while(1)
	{
		if(head1==NULL)
		{
			ptr->next=head2;
			break;
		}
		if(head2==NULL)
		{
			ptr->next=head1;
			break;
		}		
		else
		{
			ptr->next=head1;
			ptr=head1;
			head1=head1->next;
			
			ptr->next=head2;
			ptr=head2;
			head2=head2->next;
		}
	}
	return temp.next;
}
void splitLinkedList(struct node *source,struct node **frontRef,struct node **backRef)
{
	struct node *temp=source;
	int len=0;
	while(temp!=NULL)
	{
		len++;
		temp=temp->next;
	}
	if(len<2)
	{
		*frontRef=source;
		*backRef=NULL;
		return;
	}
	struct node *curr=source;
	int count=(len-1)/2;
	for(int i=0;i<count;i++)
		curr=curr->next;
	*frontRef=source;
	*backRef=curr->next;
	curr->next=NULL;
}
int main()
{
	push(&head1, 7);
    push(&head1, 5);
    push(&head1, 3);
    push(&head1, 1);
	cout<<"First Linked list:";
	printLinkedlist(head1);
	push(&head2, 10);
    push(&head2, 8);
    push(&head2, 6);
    push(&head2, 4);
    push(&head2, 2);
	cout<<"\nSecond Linked list:";
	printLinkedlist(head2);
	struct node *head=alternateMerge(head1,head2);
	cout<<"\nAfter Merge:";
	printLinkedlist(head);
	struct node *a=NULL,*b=NULL;
	splitLinkedList(head,&a,&b);
	cout<<"\nAfter splitting,first List :";
	printLinkedlist(a);
	cout<<"\nAfter splitting,second List :";
	printLinkedlist(b);
	return 0;
}
