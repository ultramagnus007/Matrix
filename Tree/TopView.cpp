/*
Print Nodes in Top View of Binary Tree

Top view of a binary tree is the set of nodes visible when the tree is viewed from the top. Given a binary tree, print the top view of it. The output nodes can be printed in any order. Expected time complexity is O(n)

       1
    /     \
   2       3
  /  \    / \
 4    5  6   7
Top view of the above binary tree is
4 2 1 3 7
*/

#include <iostream>
#include "BST.h"
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;

void TopView(node * ptr, int d, int b, unordered_map<int, pair<int, int>> &HT)
{
	if(ptr == NULL)
		return;
	unordered_map<int, pair<int, int>>::iterator it = HT.find(b);
	if(it == HT.end())
		HT[b] = pair<int, int>(d, ptr->key);
	else if(d < it->second.first)
		it->second.second = ptr->key;
	TopView(ptr->left, d+1, b-1, HT);
	TopView(ptr->right, d+1, b+1, HT);
}

bool comp(const pair<int, int> &p1, const pair<int, int> &p2)
{
	return p1.first < p2.first;
}

int main()
{
	node * root = NULL;

	#if 1
	BST bst;
	bst.insert(84);bst.insert(75);bst.insert(49);bst.insert(15);bst.insert(92);
	bst.insert(59);bst.insert(27);bst.insert(38);bst.insert(55);bst.insert(62);
	root = bst.root;
	#else
	node * ptr1 = new node(1);
	node * ptr2 = new node(2);
	node * ptr3 = new node(3);
	node * ptr4 = new node(4);
	node * ptr5 = new node(5);
	node * ptr6 = new node(6);
	node * ptr7 = new node(7);

	ptr1->left = ptr2;
	ptr1->right = ptr3;

	ptr2->left = ptr4;
	ptr2->right = ptr5;

	ptr3->left = ptr6;
	ptr3->right = ptr7;

	root = ptr1;
	#endif
	//depth and breadth
	int d = 0;
	int b = 0;

	unordered_map<int, pair<int, int>> HT;
	TopView(root, d, b, HT);
	vector<pair<int, int>> V;
	for(auto &it : HT)
		V.push_back(pair<int, int>(it.first, it.second.second));
	sort(V.begin(), V.end(), comp);
	for(auto &p: V)
		cout<<p.second<<" ";
	cout<<endl;
	return 0;
}
