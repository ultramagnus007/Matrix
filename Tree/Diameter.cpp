#include <iostream>
#include "BST.h"
using namespace std;


int Diameter(node *ptr, int &dim)
{
	if(ptr == NULL)
		return 0;
	int L = Diameter(ptr->left, dim);
	L+=(ptr->left != NULL);
	int R = Diameter(ptr->right, dim);
	R+=(ptr->right != NULL);
	dim = max(L+R, dim);
	return max(L, R);
}


int main()
{
	BST	bst;
	bst.insert(84);bst.insert(75);bst.insert(49);bst.insert(15);bst.insert(92);
	bst.insert(59);bst.insert(27);bst.insert(38);bst.insert(55);bst.insert(62);
	bst.insert(68);bst.insert(69);bst.insert(68);bst.insert(69);
	int dim = 0;
	Diameter(bst.root, dim);
	cout<<dim<<endl;
	return 0;
}
