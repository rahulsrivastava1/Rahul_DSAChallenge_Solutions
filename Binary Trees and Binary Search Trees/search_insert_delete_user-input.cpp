// search,delete,insert a user-input node in binary tree

#include<bits/stdc++.h>
using namespace std;
class BST
{
	int data;
	BST *left,*right;
	public:
		// Default constructor
		BST();
		// Parameterized constructor
		BST(int);
		// Search function.
		BST *search(BST*,int);
		// Insert function.
		BST *insert(BST*,int);
		// Inorder traversal.
		void inorder(BST*);
};
// Default constructor definition.
BST ::BST()
    : data(0)
    , left(NULL)
    , right(NULL)
{
}
// Parameterized Constructor definition.
BST ::BST(int value)
{
    data = value;
    left = right = NULL;
}
// function to search a given key in a given BST
BST* BST::search(BST* root, int key)
{
    // Base Cases: root is null or key is present at root
    if (root == NULL || root->data == key)
       return root;
    
    // Key is greater than root's key
    if (root->data < key)
       return search(root->right,data);
 
    // Key is smaller than root's key
    return search(root->left, key);
}
// function to insert a given key in a given BST
BST* BST ::Insert(BST* root, int value)
{
    if (!root)
    {
        // Insert the first node, if root is NULL.
        return new BST(value);
    }
 
    // Insert data.
    if (value > root->data)
    {
        // Insert right node data, if the 'value'
        // to be inserted is greater than 'root' node data.
 
        // Process right nodes.
        root->right = Insert(root->right, value);
    }
    else
    {
        // Insert left node data, if the 'value'
        // to be inserted is greater than 'root' node data.
 
        // Process left nodes.
        root->left = Insert(root->left, value);
    }
 
    // Return 'root' node, after insertion.
    return root;
}
 
// Inorder traversal function.
// This gives data in sorted order.
void BST ::Inorder(BST* root)
{
    if (!root) {
        return;
    }
    Inorder(root->left);
    cout << root->data << endl;
    Inorder(root->right);
}
struct node* deleteNode(struct node* root, int key)
{
    // base case
    if (root == NULL)
        return root;
 
    // If the key to be deleted is
    // smaller than the root's
    // key, then it lies in left subtree
    if (key < root->key)
        root->left = deleteNode(root->left, key);
 
    // If the key to be deleted is
    // greater than the root's
    // key, then it lies in right subtree
    else if (key > root->key)
        root->right = deleteNode(root->right, key);
 
    // if key is same as root's key, then This is the node
    // to be deleted
    else {
        // node has no child
        if (root->left==NULL and root->right==NULL)
            return NULL;
       
        // node with only one child or no child
        else if (root->left == NULL) {
            struct node* temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL) {
            struct node* temp = root->left;
            free(root);
            return temp;
        }
 
        // node with two children: Get the inorder successor
        // (smallest in the right subtree)
        struct node* temp = minValueNode(root->right);
 
        // Copy the inorder successor's content to this node
        root->key = temp->key;
 
        // Delete the inorder successor
        root->right = deleteNode(root->right, temp->key);
    }
    return root;
}
// Driver code
int main()
{
    BST b, *root = NULL;
    root = b.Insert(root, 50);
    b.Insert(root, 30);
    b.Insert(root, 20);
    b.Insert(root, 40);
    b.Insert(root, 70);
    b.Insert(root, 60);
    b.Insert(root, 80);
 
    b.Inorder(root);
    root = deleteNode(root, 20);
    cout << "Inorder traversal of the modified tree \n";
    b.Inorder(root);
    return 0;
}
