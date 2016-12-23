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
		else if(key < in[mid])
			hi = mid-1;
		else
			lo = mid+1;
	}
	return -1;
}

node * ConstructTree(vector<int> &in, vector<int> &post, int &i, int lo, int hi)
{
	if(lo > hi)
		return NULL;
	int split = bsearch(in, post[i], lo, hi);
	node * ptr = new node(post[i--]);
	ptr->right = ConstructTree(in, post, i, split+1, hi);
	ptr->left = ConstructTree(in, post, i, lo, split-1);
	return ptr;
}

int main()
{
	vector<int> in = {1,  5,  10,  15,  21,  35,  36,  39,  40,  50,  60,  65,  74,  77,  78,  79,  80,  95};
	vector<int> post = {1,  5,  15,  10,  39,  36,  40,  35,  21,  65,  60,  77,  78,  79,  80,  95,  74,  50};
    int N = in.size();
    BST bst;
    int i = N-1;
    bst.root = ConstructTree(in, post, i, 0, N-1);
    preorder(bst.root);
    cout<<endl;
    inorder(bst.root);
    cout<<endl;
    postorder(bst.root);
    cout<<endl;
    return 0;
}

