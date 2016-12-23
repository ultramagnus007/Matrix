#include <iostream>
#include "BST.h"
using namespace std;

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
    inorder(mbst.root);
	cout<<endl;
    return 0;
}

