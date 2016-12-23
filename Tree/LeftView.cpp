#include <iostream>
#include "BST.h"
using namespace std;


void LeftView(node * ptr, int depth, int &globaldepth)
{
	if(ptr == NULL)
		return;
	if(depth > globaldepth)
	{
		cout<<ptr->key<<" ";
		globaldepth = depth;
	}
	LeftView(ptr->left, depth+1, globaldepth);
	LeftView(ptr->right, depth+1, globaldepth);
}

int main()
{
	BST bst;
	bst.insert(49);bst.insert(15);bst.insert(92);bst.insert(59);bst.insert(27);
	bst.insert(84);bst.insert(75);bst.insert(38);bst.insert(55);bst.insert(58);
	bst.insert(62);
	int globaldepth = -1;
	LeftView(bst.root, 0, globaldepth);
	cout<<endl;
	return 0;
}
