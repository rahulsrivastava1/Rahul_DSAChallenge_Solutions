// height,diameter,number of nodes,number of leaf nodes,distance between two nodes

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
int diameter(struct node *root)
{
	if(root==NULL)
		return 0;
	int lheight=height(root->left);
	int rheight=height(root->right);
	int ldiameter=diameter(root->left);
	int rdiameter=diameter(root->right);
	return max(lheight+rheight+1,max(ldiameter,rdiameter));
}
int noofnodes(struct node *root)
{
	int heig=height(root);
	return (2^(heig+1))-1;
}
unsigned int noofleafnodes(struct node *root)
{
	if(root==NULL)
		return 0;
	else if(root->left==NULL && root->right==NULL)
		return 1;
	else
		return noofleafnodes(root->left)+noofleafnodes(root->right);
}
int findLevel(struct node *root,int k,int level)
{
	if(root==NULL)
		return -1;
	if(root->data==k)
		return level;
	int l=findLevel(root->left,k,level+1);
	return (l!=-1)?l:findLevel(root->right,k,level+1);
}
struct node *findDistUtil(struct node *root,int n1,int n2,int &d1,int &d2,int &dist,int level)
{
	if(root==NULL)
		return NULL;
	if(root->data==n1)
	{
		d1=level;
		return root;
	}
	if(root->data==n2)
	{
		d2=level;
		return root;
	}
	struct node *left_lca=findDistUtil(root->left,n1,n2,d1,d2,dist,level+1);
	struct node *right_lca=findDistUtil(root->right,n1,n2,d1,d2,dist,level+1);
	if(left_lca && right_lca)
	{
		dist=d1+d2-2*level;
		return root;
	}
	return (left_lca!=NULL)?left_lca:right_lca;
}
int distancebetween2nodes(struct node *root,int n1,int n2)
{
	int d1=-1,d2=-1,dist;
	struct node *lca=findDistUtil(root,n1,n2,d1,d2,dist,1);
	if(d1!=-1 && d2!=-1)
		return dist;
	if(d1!=-1)
	{
		dist=findLevel(lca,n2,0);
		return dist;
	}
	if(d2!=-1)
	{
		dist=findLevel(lca,n1,0);
		return dist;
	}
	return -1;
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
	cout<<"Height of binary tree : "<<height(root);
	cout<<"\nDiameter of binary tree : "<<diameter(root);
	cout<<"\nNo. of nodes in binary tree : "<<noofnodes(root);
	cout<<"\nNo. of leaf nodes in binary tree : "<<noofleafnodes(root);
	cout<<"\nDistance between 4 and 5 nodes in binary tree : "<<distancebetween2nodes(root,4,5);
	return 0;
}
