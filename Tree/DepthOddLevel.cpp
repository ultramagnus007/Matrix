/*
Write a C code to get the depth of the deepest odd level leaf node in a binary tree. 
Consider that level starts with 1. Depth of a leaf node is number of nodes on the path 
from root to leaf (including both leaf and root).
*/
#include <iostream>
#include "BST.h"
using namespace std;

int OddHeight(node *ptr, int level)
{
	if(ptr == NULL)
		return level;
	level++;
	int L = OddHeight(ptr->left, level);
	int R = OddHeight(ptr->right, level);
	if(L%2==0)L=0;
	if(R%2==0)R=0;
	return max(L, R);
}

int main()
{
	BST bst;
	bst.insert(84);bst.insert(75);bst.insert(49);bst.insert(15);bst.insert(92);
	bst.insert(59);bst.insert(27);bst.insert(38);bst.insert(39);bst.insert(55);bst.insert(62);
	cout<<OddHeight(bst.root, 0)<<endl;
	return 0;
}

