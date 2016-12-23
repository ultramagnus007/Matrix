#include <iostream>
#include "BST.h"
using namespace std;


int Height(node * ptr)
{
	if(ptr == NULL)
		return 0;
	int L = Height(ptr->left);
	int R = Height(ptr->right);
	L+=(ptr->left!=NULL);
	R+=(ptr->right!=NULL);
	return max(L, R);
}

int main()
{
        BST bst;
        bst.insert(84);bst.insert(75);bst.insert(49);bst.insert(15);bst.insert(92);
        bst.insert(59);bst.insert(27);bst.insert(38);bst.insert(55);bst.insert(62);
        cout<<Height(bst.root)<<endl;
        return 0;
}
