#include "BST.h"
#include <iostream>
#include <vector>
using namespace std;


node * Array2BST(vector<int> &a, int lo, int hi)
{
	if(lo > hi)
		return NULL;
	int mid = (lo+hi)/2;
	node * ptr = new node(a[mid]);
	ptr->left = Array2BST(a, lo, mid-1);	
	ptr->right = Array2BST(a, mid+1, hi);	
	return ptr;
}
int main()
{
	int N;
	cout<<"Enter N\n";
	cin>>N;
	vector<int> a(N);
	for(int i = 0; i < N; i++)
		a[i] = i+1;
	BST bst;
	bst.root = Array2BST(a, 0, N-1);
	cout<<"Hi\n"<<endl;
	preorder(bst.root);
	cout<<endl;
	inorder(bst.root);
	cout<<endl;
	postorder(bst.root);
	cout<<endl;
	return 0;
}
