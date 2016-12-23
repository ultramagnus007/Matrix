/*
Remove all nodes which don’t lie in any path with sum>= k
*/
#include <iostream>
#include "BST.h"
using namespace std;


bool RemoveSumK(node *ptr, int K)
{
	if(ptr == NULL)
		return K > 0;
	bool l = RemoveSumK(ptr->left, K - ptr->key);
	bool r = RemoveSumK(ptr->right, K - ptr->key);
	if(l) ptr->left = NULL;
	if(r) ptr->right = NULL;
	if(l && r)	
	{
		delete ptr;
		return true;
	}
	return false;
}


int main()
{
	BST bst;
	bst.insert(49);bst.insert(15);bst.insert(92);bst.insert(59);bst.insert(27);
	bst.insert(84);bst.insert(75);bst.insert(38);bst.insert(55);bst.insert(58);
	inorder(bst.root);
	cout<<endl;
	int K = 314;
	if(RemoveSumK(bst.root, K))
	{
		delete bst.root;
		bst.root = NULL;
	}
	inorder(bst.root);
	cout<<endl;
	return 0;
}
