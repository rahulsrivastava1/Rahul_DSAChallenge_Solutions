// nth ancestor of a node

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
struct node *temp=NULL;
struct node *nthAncestor(struct node *root,int node,int &k)
{
	if(!root)
		return NULL;
	if(root->data==node || (temp=nthAncestor(root->left,node,k)) || (temp=nthAncestor(root->right,node,k)))
	{
		if(k>0)
			k--;
		else if(k==0)
		{
			cout<<"nth ancestor is:"<<root->data;
			return NULL;
		}
		return root;
	}
}
int main()
{
    // Let us create binary tree shown in above diagram
    struct node *root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
 
    int k = 2;
    int node = 5;
 
    // print kth ancestor of given node
    struct node *parent = nthAncestor(root,node,k);
     
    // check if parent is not NULL, it means
    // there is no Kth ancestor of the node
    if (parent)
        cout << "-1";
     
    return 0;
}
