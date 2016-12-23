#include <iostream>
#include "BST.h"
using namespace std;

node::node(int key, int val)
{
	left = right = next = NULL;
	this->key = key;
	this->val = val;
}


BST::BST()
{
	root = NULL;
}	
void BST::insert(int key, int val)
{
	root = insert(root, key, val);
}

node * BST::insert(node * ptr, int key, int val)
{
	if(ptr == NULL)
		return new node(key, val);
	if(ptr->key > key)
		ptr->left = insert(ptr->left, key, val);
	else if(ptr->key < key)
		ptr->right = insert(ptr->right, key, val);
	else
		ptr->val = val;
	return ptr;
}

void preorder(node *ptr)
{
	if(ptr == NULL)
		return;
	cout<<ptr->key<<" ";
	if(ptr->left != NULL)
		preorder(ptr->left);
	if(ptr->right != NULL)
		preorder(ptr->right);
}

void inorder(node *ptr)
{
	if(ptr == NULL)
		return;
	if(ptr->left != NULL)
		inorder(ptr->left);
	cout<<ptr->key<<" ";
	if(ptr->right != NULL)
		inorder(ptr->right);
}

void postorder(node *ptr)
{
	if(ptr == NULL)
		return;
	if(ptr->left != NULL)
		postorder(ptr->left);
	if(ptr->right != NULL)
		postorder(ptr->right);
	cout<<ptr->key<<" ";
}

#if 0
int main()
{
        BST bst;
        bst.insert(79);bst.insert(94);bst.insert(29);bst.insert(64);bst.insert(21);
        bst.insert(56);bst.insert(63);bst.insert(10);bst.insert(98);bst.insert(58);

        preorder(bst.root);
        cout<<endl;
        inorder(bst.root);
        cout<<endl;
        postorder(bst.root);
        cout<<endl;
        return 0;
}
#endif
