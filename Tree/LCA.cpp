#include <iostream>
#include "BST.h"
using namespace std;


int LCABST(node *ptr, int a, int b)
{
	if(ptr == NULL)
		return -1;
	if(ptr->key > b)
		return LCABST(ptr->left, a, b);
	if(ptr->key < a)
		return LCABST(ptr->right, a, b);
	return ptr->key;
}


int LCA(node *ptr, int a, int b)
{
	if(ptr == NULL)
		return -1;
	if(ptr->key == a || ptr->key == b)
		return ptr->key;
	int L = LCA(ptr->left, a, b);
	int R = LCA(ptr->right, a, b);
	if((L == a || L == b) && (R == a || R == b) )
		return ptr->key;
	if(L != -1)
		return L;
	if(R != -1)
		return R;
	return -1;
}

int main()
{
	BST bst;
	bst.insert(50);bst.insert(21);bst.insert(74);bst.insert(10);bst.insert(35);
	bst.insert(60);bst.insert(5);bst.insert(15);bst.insert(40);bst.insert(65);
	bst.insert(95);bst.insert(1);bst.insert(36);bst.insert(39);bst.insert(80);bst.insert(79);bst.insert(78);bst.insert(77);
	cout<<LCABST(bst.root, 15,  39)<<endl;
	#if 1
	cout<<LCA(bst.root, 15,  39)<<endl;
	cout<<LCA(bst.root, 36,  39)<<endl;
	cout<<LCA(bst.root, 65,  80)<<endl;
	cout<<LCA(bst.root, 39,  65)<<endl;
	cout<<LCA(bst.root, 1, 5)<<endl;
	#endif
	return 0;
}

