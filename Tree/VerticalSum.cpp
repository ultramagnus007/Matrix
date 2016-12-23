/*
Given a Binary Tree, find vertical sum of the nodes that are in same vertical line. Print all sums through different vertical lines.

Examples:
      1
    /   \
  2      3
 / \    / \
4   5  6   7

The tree has 5 vertical lines

Vertical-Line-1 has only one node 4 => vertical sum is 4
Vertical-Line-2: has only one node 2=> vertical sum is 2
Vertical-Line-3: has three nodes: 1,5,6 => vertical sum is 1+5+6 = 12
Vertical-Line-4: has only one node 3 => vertical sum is 3
Vertical-Line-5: has only one node 7 => vertical sum is 7

So expected output is 4, 2, 12, 3 and 7
*/

#include <iostream>
#include <vector>
#include <deque>
#include "BST.h"
using namespace std;


void VerticalSum(node *ptr, int i, int &start, deque<int> &Q)
{
	if(ptr == NULL)
		return;
	start = min(start, i);
	if(i-start == 0)
		Q.push_front(ptr->key);
	else if(i-start >= Q.size())
		Q.push_back(ptr->key);
	else
		Q[i-start] += ptr->key;
	VerticalSum(ptr->left, i-1, start, Q);
	VerticalSum(ptr->right, i+1, start, Q);
}

int main()
{
	const int N = 7;
	vector<node *> a(N);
	for(int i = 0; i < N; i++)
		a[i] = new node(i+1);

	a[0]->left = a[1];
	a[0]->right = a[2];
	a[1]->left = a[3];
	a[1]->right = a[4];
	a[2]->left = a[5];
	a[2]->right = a[6];

	deque<int> Q;
	int i = 0;
	int start = 0;
	VerticalSum(a[0], i, start, Q);
	for(auto &x:Q)
		cout<<x<<" ";
	cout<<endl;
	return 0;
}
