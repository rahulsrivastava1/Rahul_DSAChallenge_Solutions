// delete m nodes after n nodes

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
void skipNdeleteM(struct node *head,int m,int n)
{
	struct node *curr=head,*t;
	int count;
	while(curr)
	{
		for(count=1;count<n&&curr!=NULL;count++)
			curr=curr->next;
		if(curr==NULL)
			return;
		t=curr->next;
		for(count=1;count<=m&&t!=NULL;count++)
		{
			struct node *temp=t;
			t=t->next;
			free(temp);
		}
		curr->next=t;
		curr=t;
	}
}
int main()
{
	int size,m,n;
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
	cout<<"\nEnter the position from you want to delete nodes:";
	cin>>n;
	cout<<"Enter how mamy nodes you want to delete:";
	cin>>m;
	skipNdeleteM(head,m,n);
	cout<<"printing the linkedlist after all operations:";
	struct node *ptr;
	ptr=head;
	while(ptr!=NULL)
	{
		cout<<ptr->data<<" ";
		ptr=ptr->next;
	}
	return 0;
}
