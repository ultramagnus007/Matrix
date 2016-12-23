#include <iostream>
#include <unordered_map>
#include "BST.h"
#include <queue>
using namespace std;



class Hash
{
	public:
	size_t operator()(const node * p)const
	{
		return p->key/1021;
	}
};

class Compare
{
	public:
	bool operator()(const node *p1, const node *p2)const
	{
		return p1==p2;
	}	
};

void fillBreadth(node *ptr, int &minB, int b, unordered_map<node *, int, Hash, Compare> &HT)
{
	if(ptr == NULL)
		return;
	minB = min(minB, b);
	HT[ptr] = b;
	fillBreadth(ptr->left, minB, b-1, HT);
	fillBreadth(ptr->right, minB, b+1, HT);
}

void PrettyPrint(node *ptr)
{
	if(ptr == NULL)
		return;
	unordered_map<node *, int, Hash, Compare> HT(1021, Hash(), Compare());
	int minB = 0;
	fillBreadth(ptr, minB, 0, HT);
		queue<node *> Q;
	Q.push(ptr);
	int curl=1;
	int nextl=0;
	int preB = 0;
	while(!Q.empty())
	{
		node *ptr = Q.front();
		Q.pop();
		int b = HT[ptr]	- minB;
		int space = b - preB;
		preB = b;
		while(space-- != 0)
			cout<<"	";
		cout<<ptr->key;
		if(ptr->left != NULL)
		{
			Q.push(ptr->left);
			nextl++;
		}
		if(ptr->right != NULL)
		{
			Q.push(ptr->right);
			nextl++;
		}
		curl--;
		if(curl==0)
		{
			curl = nextl;
			nextl = 0;
			cout<<endl;
			preB = 0;
		}
	}
}

int main()
{
	BST bst;
	bst.insert(84);bst.insert(75);bst.insert(49);bst.insert(15);bst.insert(92);
	bst.insert(59);bst.insert(27);bst.insert(38);bst.insert(55);bst.insert(62);
	PrettyPrint(bst.root);
	return 0;
}
