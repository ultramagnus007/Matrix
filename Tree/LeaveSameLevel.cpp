#include <iostream>
#include "BST.h"
using namespace std;


bool LeafSameLevel(node *ptr, int &baseH, int curH)
{
	if(ptr == NULL)
		return true;
	if(ptr->left == NULL && ptr->right == NULL)
	{
		if(baseH == -1)
		{
			baseH = curH;
			return true;
		}		
		return baseH == curH;
	}
	return LeafSameLevel(ptr->left, baseH, curH+1) && 
				LeafSameLevel(ptr->right, baseH, curH+1);
}
bool LeafSameLevel(node * ptr)
{
	if(ptr == NULL)
		return true;
	int baseH = -1; 
	int curH = -1;
	LeafSameLevel(ptr, baseH, curH+1);
}

int main()
{
    BST bst;
    #if 0
    bst.insert(84);bst.insert(75);bst.insert(49);bst.insert(15);bst.insert(92);
    bst.insert(59);bst.insert(27);bst.insert(38);bst.insert(55);bst.insert(62);
    #else
    bst.insert(10);bst.insert(5);bst.insert(8);bst.insert(9);bst.insert(7);bst.insert(2);bst.insert(3);bst.insert(1);
    bst.insert(15);bst.insert(18);bst.insert(19);bst.insert(17);bst.insert(12);bst.insert(13);bst.insert(11);
    #endif
    if(LeafSameLevel(bst.root))
        cout<<"Same Level"<<endl;
    else
        cout<<"Not Same Level"<<endl;
    return 0;
}
