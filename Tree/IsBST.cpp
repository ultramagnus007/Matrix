#include <iostream>
#include "BST.h"
#include <climits>
using namespace std;

#if 0
// Brute Force
int findMax(node * ptr)
{
	if(ptr == NULL)
		return INT_MIN;
	return max(ptr->key, max(findMax(ptr->left), findMax(ptr->right)));
}

int findMin(node * ptr)
{
	if(ptr == NULL)
		return INT_MAX;
	return min(ptr->key, min(findMin(ptr->left), findMin(ptr->right)));
}


bool isBST(node * ptr)
{
	if(ptr == NULL)
		return true;
	if(isBST(ptr->left) == false || isBST(ptr->right) == false)
		return false;
	return ptr->key >= findMax(ptr->left)&& ptr->key <= findMin(ptr->right);
}
#endif 

#if 0
bool isBST(node * ptr, int &L, int &R)
{
	if(ptr == NULL)
		return true;
	int l = INT_MIN;
	int r = INT_MAX;
	if(isBST(ptr->left, l, r) == false || ptr->key < l)
		return false;
	L = max(ptr->key, l);
	R = min(ptr->key, r);
	l = INT_MIN;
	r = INT_MAX;
	if(isBST(ptr->right, l, r) == false || ptr->key > r)
		return false;
	L = max(ptr->key, l);
	R = min(ptr->key, r);
	return true;
}
bool isBST(node * ptr)
{
	if(ptr == NULL)
		return true;
	int L = INT_MIN;
	int R = INT_MAX;
	return isBST(ptr, L, R);
}
#endif


// inorder traversal based
bool isBST(node * ptr, int &pre)
{
	if(ptr == NULL)
		return true;
	if(isBST(ptr->left, pre) == false)
		return false;
	if(ptr->key < pre)
		return false;
	pre = ptr->key;
	if(isBST(ptr->right, pre) == false)
		return false;
	return true; 
}
bool isBST(node * ptr)
{
	int pre = INT_MIN;
	return isBST(ptr, pre);
}


int main()
{
        BST bst;
        node * root = NULL;
        #if 1
        bst.insert(50);bst.insert(21);bst.insert(74);bst.insert(10);bst.insert(35);
        bst.insert(60);bst.insert(5);bst.insert(15);bst.insert(40);bst.insert(65);
        bst.insert(95);bst.insert(1);bst.insert(36);bst.insert(39);bst.insert(80);
        bst.insert(79);bst.insert(78);bst.insert(77);
        root = bst.root;
        #else

        root = new node(3);
        root->left = new node(2);
        root->right = new node(5);
        root->left->left = new node(1);
        root->left->right = new node(4);
        #endif
        if(isBST(root))
                cout<<"YES BST"<<endl;
        else
                cout<<"NOT BST"<<endl;

        return 0;
}

