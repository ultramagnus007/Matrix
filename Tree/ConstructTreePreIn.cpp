#include <iostream>
#include "BST.h"
#include <vector>
using namespace std;



int bsearch(vector<int> &in, int key, int lo, int hi)
{
	while(lo <= hi)
	{
		int mid = (lo+hi)/2;
		if(key == in[mid])
			return mid;
		else if(key > in[mid])
			lo = mid+1;
		else
			hi = mid-1;
	}
	return -1;
}

node *ConstructTree(vector<int> &in, vector<int> &pre, int &i, int lo, int hi)
{
	if(lo > hi)
		return NULL;
	int split = bsearch(in, pre[i], lo, hi);
	node * ptr = new node(pre[i++]);
	ptr->left = ConstructTree(in, pre, i, lo, split-1);
	ptr->right = ConstructTree(in, pre, i, split+1, hi);
	return ptr;
}


int main()
{
	vector<int> pre = {50,  21,  10,  5,  1,  15,  35,  40,  36,  39,  74,  60,  65,  95,  80,  79,  78,  77};
	vector<int> in =  {1,  5,  10,  15,  21,  35,  36,  39,  40,  50,  60,  65,  74,  77,  78,  79,  80,  95};
	int N = pre.size();
	BST bst;
	int i = 0;
	bst.root = ConstructTree(in, pre, i, 0, N-1);
	preorder(bst.root);
	cout<<endl;
	inorder(bst.root);
	cout<<endl;
	postorder(bst.root);
	cout<<endl;
    return 0;
}

