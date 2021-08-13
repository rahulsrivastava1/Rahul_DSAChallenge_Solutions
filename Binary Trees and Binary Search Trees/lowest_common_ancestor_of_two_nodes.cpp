// lowest common ancestors of two nodes

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
bool findPath(struct node *root,vector<int> &path,int k)
{
	if(root==NULL)
		return false;
	path.push_back(root->data);
	if(root->data==k)
		return true;
	if((root->left && findPath(root->left,path,k))|| (root->right && findPath(root->right,path,k)))
		return true;
	path.pop_back();
	return false;
}
int findLCA(struct node *root,int n1,int n2)
{
	vector<int> path1,path2;
	if(!findPath(root,path1,n1) || !findPath(root,path2,n2))
		return -1;
	int i;
	for(i=0;i<path1.size() && i<path2.size();i++)
	{
		if(path1[i]!=path2[i])
			break;
	}
	return path1[i-1];
}
int main()
{
    // Let us create the Binary Tree shown in above diagram.
    node * root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right->left = new node(6);
    root->right->right = new node(7);
    cout << "LCA(4, 5) = " << findLCA(root, 4, 5);
    cout << "\nLCA(4, 6) = " << findLCA(root, 4, 6);
    cout << "\nLCA(3, 4) = " << findLCA(root, 3, 4);
    cout << "\nLCA(2, 4) = " << findLCA(root, 2, 4);
    return 0;
}
