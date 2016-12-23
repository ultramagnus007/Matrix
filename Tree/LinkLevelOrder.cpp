#include <iostream>
#include <queue>
#include "BST.h"
using namespace std;


void LinkLevelOrderO1(node *ptr)
{
	if(ptr == NULL)
		return;
	node * pre = NULL;
	while(ptr != NULL)
	{
	
		
	

	}
}
void LinkLevelOrder(node *root)
{
	if(root == NULL)
		return;
	queue<node *> Q;
	Q.push(root);
	node *pre = NULL;
	while(!Q.empty())
	{
		node * ptr = Q.front();
		Q.pop();
		if(pre != NULL)
			pre->next = ptr;
		pre = ptr;
		if(ptr->left != NULL)		
			Q.push(ptr->left);
		if(ptr->right != NULL)
			Q.push(ptr->right);
	}

	node *ptr = root;
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
	LinkLevelOrder(bst.root);	
	LinkLevelOrderO1(bst.root);
	return 0;
}
