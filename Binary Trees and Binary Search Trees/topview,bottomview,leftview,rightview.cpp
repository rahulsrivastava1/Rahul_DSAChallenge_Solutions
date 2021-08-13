// top-view,bottom-view,left-view,right-view

#include<bits/stdc++.h>
using namespace std;
struct node
{
	int data;
	int hd;
	struct node *left;
	struct node *right;
	node(int val)
	{
		hd=INT_MAX;
		data=val;
		left=NULL;
		right=NULL;	
	}	
};
void topview(struct node *root)
{
	if(root==NULL)
		return;
	queue<struct node*> q;
	map<int,int> mp;
	int hd=0;
	root->hd=hd;
	q.push(root);
	cout<<"Top view of the tree is:";
	while(q.size())
	{
		hd=root->hd;
		if(mp.count(hd)==0)
			mp[hd]=root->data;
		if(root->left)
		{
			root->left->hd=hd-1;
			q.push(root->left);
		}
		if(root->right)
		{
			root->right->hd=hd+1;
			q.push(root->right);
		}		
		q.pop();
		root=q.front();
	}
	for(auto it=mp.begin();it!=mp.end();it++)
		cout<<it->second<<" ";
}
void bottomview(struct node *root)
{
	if(root==NULL)
		return;
	queue<struct node*> q;
	map<int,int> mp;
	int hd=0;
	root->hd=hd;
	q.push(root);
	cout<<"\nBottom view of the tree is:";
	while(!q.empty())
	{
		struct node *temp=q.front();
		q.pop();
		hd=temp->hd;
		mp[hd]=temp->data;
		if(temp->left!=NULL)
		{
			temp->left->hd=hd-1;
			q.push(temp->left);
		}
		if(temp->right!=NULL)
		{
			temp->right->hd=hd+1;
			q.push(temp->right);
		}
	}
	for(auto it=mp.begin();it!=mp.end();it++)
		cout<<it->second<<" ";
}
void leftViewUtil(struct node *root,int lvl,int *max_lvl)
{
	if(root==NULL)
		return ;
	if(*max_lvl<lvl)
	{
		cout<<root->data<<" ";
		*max_lvl=lvl;
	}
	leftViewUtil(root->left, lvl + 1, max_lvl);
    leftViewUtil(root->right, lvl + 1, max_lvl);
}
void leftview(struct node *root)
{
	int max_level=0;
	leftViewUtil(root,1,&max_level);
}
void rightViewUtil(struct node *root,int lvl,int *max_lvl)
{
	if(root==NULL)
		return ;
	if(*max_lvl<lvl)
	{
		cout<<root->data<<" ";
		*max_lvl=lvl;
	}
	rightViewUtil(root->right, lvl + 1, max_lvl);
    rightViewUtil(root->left, lvl + 1, max_lvl);
}
void rightview(struct node *root)
{
	int max_level=0;
	leftViewUtil(root,1,&max_level);
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
	topview(root);
	bottomview(root);
	cout<<"\nLeft view of the tree is:";
	leftview(root);
	cout<<"\nRight view of the tree is:";
	rightview(root);
	return 0;
}
