// given linked list is palindrome or not

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
bool isPalindrome(struct node *head)
{
	struct node *temp=head;
	stack<int> st;
	while(temp!=NULL)
	{
		st.push(temp->data);
		temp=temp->next;
	}
	while(head!=NULL)
	{
		int x=st.top();
		st.pop();
		if(head->data!=x)
			return false;
		head=head->next;
	}
	return true;
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
	int ans=isPalindrome(head);
	if(ans==1)
		cout<<"\nLinked list is palindrome!";
	else
		cout<<"\nLinked list is not palindrome!";
	return 0;
}
