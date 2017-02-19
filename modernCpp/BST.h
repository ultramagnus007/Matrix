#ifndef _BST_H_
#define _BST_H_

#include <iostream>
using namespace std;

class node
{
	public:
	node(int key, int val = -1)
	{
		left = NULL;
		right = NULL;
		this->key = key;
		this->val = val;
	}
	node *left, *right;
	int key, val;
};

class BST
{
	private:
	node* insert(node* ptr, int key, int val);
	public:
	BST(){root = NULL;}
	void insert(int key, int val = -1);
	node * root;
};


void preorder(node *);
void inorder(node *);
void postorder(node *);

#endif
