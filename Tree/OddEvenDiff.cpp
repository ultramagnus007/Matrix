#include <iostream>
#include "BST.h"
using namespace std;

void OddEvenSum(node *ptr, int &OS, int &ES, int level)
{
	if(ptr == NULL)
		return;
	if(level%2==0)
		ES+=ptr->key;
	else
		OS+=ptr->key;
	
	OddEvenSum(ptr->left, OS, ES, level+1);
	OddEvenSum(ptr->right, OS, ES, level+1);
}

int main()
{
    BST bst;
    bst.insert(84);bst.insert(75);bst.insert(49);bst.insert(15);bst.insert(92);
    bst.insert(59);bst.insert(27);bst.insert(38);bst.insert(55);bst.insert(62);
    cout<<"Difference between odd level and even level is \n";
	int OS = 0;
	int ES = 0;
	int level = 1;
	OddEvenSum(bst.root, OS, ES, level);
	cout<<OS-ES<<endl;
	return 0;
}
