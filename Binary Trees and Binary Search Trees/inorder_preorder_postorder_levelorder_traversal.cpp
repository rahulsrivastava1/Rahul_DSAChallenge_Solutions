// inorder,preorder,postorder,levelorder traversal

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
void printPreorder(struct node *root)
{
	//cout<<"Preorder traversal:";
	if(root==NULL)
		return;
	cout<<root->data<<" ";
	printPreorder(root->left);
	printPreorder(root->right);
}
void printPostorder(struct node *root)
{
	//cout<<"Postorder traversal:";
	if(root==NULL)
		return;
	printPreorder(root->left);
	printPreorder(root->right);
	cout<<root->data<<" ";
}
void printInorder(struct node *root)
{
	//cout<<"Postorder traversal:";
	if(root==NULL)
		return;
	printPreorder(root->left);
	cout<<root->data<<" ";
	printPreorder(root->right);
}
int height(struct node *root)
{
	if(root==NULL)
		return 0;
	else
	{
		int lheight=height(root->left);
		int rheight=height(root->right);
		if(lheight>rheight)
			return lheight+1;
		else
			return rheight+1;
	}
}
void printCurrentLevel(struct node *root,int level)
{
	if(root==NULL)
		return;
	if(level==1)
		cout<<root->data<<" ";
	else if(level>1)
	{
		printCurrentLevel(root->left,level-1);
		printCurrentLevel(root->right,level-1);
	}
}
void printLevelorder(struct node *root)
{
	//cout<<"Level order traversal:";
	int h=height(root);
	for(int i=1;i<=h;i++)
		printCurrentLevel(root,i);
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
	cout<<"preorder traversal : ";
	printPreorder(root);
	cout<<endl;
	cout<<"inorder traversal : ";
	printInorder(root);
	cout<<endl;
	cout<<"postorder traversal : ";
	printPostorder(root);
	cout<<endl;
	cout<<"levelorder traversal : ";
	printLevelorder(root);
	return 0;
}
