//Tree Isomorphism Problem : http://www.geeksforgeeks.org/tree-isomorphism-problem/
#include <iostream>
#include <vector>
#include "BST.h"
using namespace std;

bool Isomorphic(node * p1, node *p2)
{
	if(p1 == NULL && p2 == NULL)
		return true;
	if(p1 == NULL || p2 == NULL)
		return false;
	if(p1->key != p2->key)
		return false;
	return (Isomorphic(p1->left, p2->left) && Isomorphic(p1->right, p2->right))
			|| (Isomorphic(p1->left, p2->right) && Isomorphic(p1->right, p2->left));
}

node * mirrorBST(node *ptr)
{
	if(ptr == NULL)
		return NULL;
	node *p = new node(ptr->key);
	p->right = mirrorBST(ptr->left);
	p->left = mirrorBST(ptr->right);
	return p;
}

int main()
{
    BST bst;
    bst.insert(84);bst.insert(75);bst.insert(49);bst.insert(15);bst.insert(92);
    bst.insert(59);bst.insert(27);bst.insert(38);bst.insert(55);bst.insert(62);

    BST mbst;
    mbst.root = mirrorBST(bst.root);

	if(Isomorphic(bst.root, mbst.root))
		cout<<"Yes Isomorphic"<<endl;
	else
		cout<<"No Isomorphic"<<endl;

	return 0;
}
