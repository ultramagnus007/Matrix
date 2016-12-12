#include <iostream>
#include "BST.h"
using namespace std;


node * concatenate(node * h1, node * h2)
{
	if(h1 == NULL)
		return h2;
	if(h2 == NULL)
		return h1;
	node * t1 = h1->left;
	node * t2 = h2->left;
	t1->right = h2;
	h2->left = t1;
	h1->left = t2;
	t2->right = h1;
	return h1;
}

node * BST2DLL(node * ptr)
{
	if(ptr==NULL)
		return NULL;
	node * left = ptr->left;
	node * right = ptr->right;
	ptr->left = ptr;
	ptr->right = ptr;
	left = BST2DLL(left);
	right = BST2DLL(right);
	ptr = concatenate(left, ptr);
	ptr = concatenate(ptr, right);
	return ptr;
}


int main()
{
        BST bst;
        bst.insert(84);bst.insert(75);bst.insert(49);bst.insert(15);bst.insert(92);
        bst.insert(59);bst.insert(27);bst.insert(38);bst.insert(55);bst.insert(62);
        inorder(bst.root);
        cout<<endl;



	node * head = BST2DLL(bst.root);
	node * ptr = head;
	while(ptr != NULL && ptr->right != head)
	{
		cout<<ptr->key<<" ";
		ptr = ptr->right;
	}
	if(ptr != NULL)
		cout<<ptr->key;
	cout<<endl;
	return 0;
}
