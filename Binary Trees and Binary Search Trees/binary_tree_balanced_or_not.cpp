// binary tree is balanced or not

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
bool isBalanced(struct node *root)
{
	int lh,rh;
	if(root==NULL)
		return 1;
	lh=height(root->left);
	rh=height(root->right);
	if(abs(lh-rh)<=1 && isBalanced(root->left) && isBalanced(root->right))
		return 1;
	return 0;
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
	root->left->left->left = new node(8);
    if (isBalanced(root))
        cout<<"Tree is balanced";
    else
        cout<<"Tree is not balanced";
    return 0;
}
