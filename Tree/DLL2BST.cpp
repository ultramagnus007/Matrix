#include <iostream>
#include "BST.h"
using namespace std;

node *makeDLL(int N)
{
	node * head = NULL;
	node * pre = NULL;
	for(int i = 1; i <= N; i++)
	{
		node *ptr = new node(i);
		if(i==1)
		{
			head = ptr;
		}else
		{
			pre->right = ptr;
			ptr->left = pre;
		}
		pre = ptr;
	}
	return head;
}

node * findmid(node * ptr)
{
	if(ptr == NULL)
		return NULL;
	node * sl = ptr;
	node * fa = ptr->right;
	while(fa != NULL)
	{
		fa = fa->right;
		if(fa == NULL)
			return sl;
		fa = fa->right;
		sl = sl->right;
	}
	return sl;
}

node * DLL2BST(node *ptr)
{
	if(ptr == NULL)
		return NULL;
	node * mid = findmid(ptr);
	node * L = mid->left;
	node * R = mid->right;
	if(L != NULL)
	{
		L->right = NULL;
		mid->left = NULL;
		mid->left = DLL2BST(ptr);
	}
	if(R != NULL)
	{
		R->left = NULL;
		mid->right = NULL;
		mid->right = DLL2BST(R);
	}
	return mid;
}

int main()
{
    int N = 21;
    node * head= makeDLL(N);
    BST bst;
	bst.root = DLL2BST(head);
	inorder(bst.root);
    cout<<endl;
    return 0;
}
