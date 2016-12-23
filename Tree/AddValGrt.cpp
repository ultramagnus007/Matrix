/*
Given a Binary Search Tree (BST), modify it so that all greater values
in the given BST are added to every node.
*/

#include <iostream>
#include "BST.h"

using namespace std;

void AddGreater(node *ptr, int &S)
{
	if(ptr == NULL)
		return;
	AddGreater(ptr->right, S);
	ptr->key += S;
	S = ptr->key;
	AddGreater(ptr->left, S);
}

int main()
{
	BST bst;
	bst.insert(50);bst.insert(21);bst.insert(74);bst.insert(10);bst.insert(35);
	bst.insert(60);/*bst.insert(5);bst.insert(15);bst.insert(40);bst.insert(65);
	bst.insert(95);bst.insert(1);bst.insert(36);bst.insert(39);bst.insert(80);bst.insert(79);bst.insert(78);bst.insert(77);*/

	inorder(bst.root);
	cout<<endl;
	
	int S = 0;
	AddGreater(bst.root, S);

	inorder(bst.root);
	cout<<endl;
	return 0;
}
