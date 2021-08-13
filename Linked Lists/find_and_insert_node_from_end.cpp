// find the nth node from end and insert another node

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
int main()
{
	int size;
	cout<<"Enter the size of your linked list:";
	cin>>size;
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
	int len=0,n;
	cout<<"\nEnter the position from last:";
	cin>>n;
	temp=head;
	while(temp!=NULL)
	{
		temp=temp->next;
		len++;
	}
	if(len<n)
		return 0;
	temp=head;
	for(int i=1;i<len-n+1;i++)
		temp=temp->next;
	cout<<"Data of the present at the node "<<n<<"from end :"<<temp->data<<"\n";	
	struct node *ptr;
	int val;
	ptr=(struct node *)malloc(sizeof(struct node *));
	cout<<"Enter the value of the new node:";
	cin>>val;
	ptr->data=val;
	ptr->next=temp->next;
	temp->next=ptr;
	cout<<"After inserted:";
	temp=head;
	while(temp!=NULL)
	{
		cout<<temp->data<<" ";
		temp=temp->next;
	}
	return 0;
}
