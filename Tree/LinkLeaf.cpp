#include <iostream>
#include "BST.h"
using namespace std;

void LinkLeaf(node *ptr, node*&preLeaf)
{
	if(ptr == NULL)
		return;
	LinkLeaf(ptr->left, preLeaf);
	if(ptr->left == NULL && ptr->right == NULL)
	{
		if(preLeaf != NULL)
			preLeaf->next = ptr;
		preLeaf =ptr;
	}
	LinkLeaf(ptr->right, preLeaf);
}


node * findLeaf(node *ptr)
{
	if(ptr == NULL)
		return NULL;
	if(ptr->left == NULL && ptr->right == NULL)
		return ptr;
	if(ptr->left != NULL)
		return findLeaf(ptr->left);
	return findLeaf(ptr->right);
}

void printLinkedLeaf(node * ptr)
{
	ptr = findLeaf(ptr);
	while(ptr != NULL)
	{
		cout<<ptr->key<<" ";
		ptr = ptr->next;
	}
	cout<<endl;
}

int main()
{
    BST bst;
    bst.insert(84);bst.insert(75);bst.insert(49);bst.insert(15);bst.insert(92);
    bst.insert(59);bst.insert(27);bst.insert(38);bst.insert(55);bst.insert(62);
    bst.insert(88);bst.insert(100);bst.insert(85);

    node * preLeaf = NULL;
    LinkLeaf(bst.root, preLeaf);
    printLinkedLeaf(bst.root);
    return 0;
}
