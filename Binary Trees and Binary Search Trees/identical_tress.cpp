// identical trees

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
int identicalTrees(struct node *a,struct node *b)
{
	if(a==NULL && b==NULL)
		return 1;
	if(a!=NULL && b!=NULL)
	{
		return(a->data==b->data && identicalTrees(a->left,b->left) && identicalTrees(a->right,b->right));
	}
	return 0;
}
int main()
{
    node *root1 = new node(1);
    node *root2 = new node(1);
    root1->left = new node(2);
    root1->right = new node(3);
    root1->left->left=new node(4);
    root1->left->right = new node(5);
 
    root2->left = new node(2);
    root2->right = new node(3);
    root2->left->left = new node(4);
    root2->left->right = new node(5);
 
    if(identicalTrees(root1, root2))
        cout << "Both trees are identical.";
    else
        cout << "Trees are not identical.";
 
return 0;
}
