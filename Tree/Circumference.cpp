#include <iostream>
#include "BST.h"
using namespace std;

void printRight(node *);

void printLeaf(node * ptr)
{
	if(ptr == NULL)
		return;
	if(ptr->left == NULL && ptr->right == NULL)
		cout<<ptr->key<<" ";

	printLeaf(ptr->left);
	printLeaf(ptr->right);
}

void printLeft(node * ptr)
{
	if(ptr == NULL)
		return;
	cout<<ptr->key<<" ";
	if(ptr->left != NULL)
	{
		printLeft(ptr->left);
		printLeaf(ptr->right);
	}else
	{
		printLeft(ptr->right);
	}
}

void printRight(node * ptr)
{
	if(ptr == NULL)
		return;
	if(ptr->right != NULL)
	{
		printLeaf(ptr->left);
		printRight(ptr->right);
	}else
	{
		printRight(ptr->left);
	}
	cout<<ptr->key<<" ";
}



void printCircumference(node * ptr)
{
	if(ptr == NULL)
		return;
	cout<<ptr->key<<" ";
	printLeft(ptr->left);
	printRight(ptr->right);
}

int main()
{
	BST bst;
	bst.insert(84);bst.insert(75);bst.insert(49);bst.insert(15);bst.insert(92);bst.insert(88);bst.insert(91);bst.insert(85);
	bst.insert(59);bst.insert(27);bst.insert(26);bst.insert(38);bst.insert(55);bst.insert(62);

	printCircumference(bst.root);
	cout<<endl;
	return 0;
}
