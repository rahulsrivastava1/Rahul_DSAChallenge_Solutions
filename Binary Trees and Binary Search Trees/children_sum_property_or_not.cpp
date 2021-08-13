// children sum property or not

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
int isSumProperty(struct node *root)
{
	int left_data=0,right_data=0;
	if(root==NULL || root->left==NULL && root->right==NULL)
		return 1;
	else
	{
		if(root->left!=NULL)
			left_data=root->left->data;
		if(root->right!=NULL)
			right_data=root->right->data;
		if((root->data==left_data+right_data) && (isSumProperty(root->left) && isSumProperty(root->right)))
			return 1;
		else
			return 0;
	}
}
int main()
{
	struct node *root=new node(10);
    root->left=new node(8);
    root->right=new node(2);
    root->left->left=new node(3);
    root->left->right=new node(5);
    root->right->right=new node(2);
	if(isSumProperty(root))
        cout << "The given tree satisfies "
            << "the children sum property ";
    else
        cout << "The given tree does not satisfy "
            << "the children sum property ";
    return 0;
}
