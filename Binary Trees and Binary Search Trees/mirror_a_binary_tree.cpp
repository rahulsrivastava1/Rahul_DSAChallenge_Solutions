// mirror a binary tree

#include<bits/stdc++.h>
using namespace std;
struct node
{
	int data;
	struct node *left;
	struct node *right;
	node(int val)
	{
		data=val;
		left=NULL;
		right=NULL;	
	}	
};
void mirror(struct node *root)
{
	if(root==NULL)
		return;
	else
	{
		struct node *temp;
		mirror(root->left);
		mirror(root->right);
		temp=root->left;
		root->left=root->right;
		root->right=temp;
	}
}
void printInorder(struct node *root)
{
	if(root==NULL)	
		return;
	printInorder(root->left);
	cout<<root->data<<" ";
	printInorder(root->right);
}
int main()
{
	struct node *root=new node(1);
	root->left=new node(2);
	root->right=new node(3);
	root->left->left=new node(4);
	root->left->right=new node(5);
	root->right->left=new node(6);
	root->right->right=new node(7);
	cout<<"Original tree :";
	printInorder(root);
	cout<<"\nMirror tree :";
	mirror(root);
	printInorder(root);
	return 0;
}
