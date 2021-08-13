// remove duplicates from sorted linked list

#include<bits/stdc++.h>
using namespace std;
struct node
{
	int data;
	struct node *next;
};
struct node *head=NULL;
void create()  
{  
    struct node *ptr,*temp;  
    int item;     
    ptr = (struct node*)malloc(sizeof(struct node));      
    if(ptr == NULL)  
    {  
        printf("\nOVERFLOW");     
    }  
    else  
    {  
        printf("Enter value:");  
        scanf("%d",&item);  
        ptr->data = item;  
        if(head == NULL)  
        {  
            ptr -> next = NULL;  
            head = ptr;  
            printf("Node inserted\n");  
        }  
        else  
        {  
            temp = head;  
            while (temp -> next != NULL)  
            {  
                temp = temp -> next;  
            }  
            temp->next = ptr;  
            ptr->next = NULL;  
            printf("Node inserted\n");  
          
        }  
    }  
}
void removeDuplicates(struct node *head)
{
	struct node *temp=head;
	struct node *next_next;
	if(temp==NULL)
		return;
	while(temp->next!=NULL)
	{
		if(temp->data==temp->next->data)
		{
			next_next=temp->next->next;
			free(temp->next);
			temp->next=next_next;
		}
		else
			temp=temp->next;
	}
}
int main()
{
	int size,m,n;
	cout<<"Enter the size of your linked list:";
	cin>>size;
	cout<<"Enter sorted data\n";
	while(size--)
	{
		create();
	}
	cout<<"Linked list before any operations:";
	struct node *temp=head;
	while(temp!=NULL)
	{
		cout<<temp->data<<" ";
		temp=temp->next;
	}
	removeDuplicates(head);
	cout<<"\nLinked list after removing duplicates:";
	temp=head;
	while(temp!=NULL)
	{
		cout<<temp->data<<" ";
		temp=temp->next;
	}
	return 0;
}
