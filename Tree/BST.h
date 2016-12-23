#ifndef _BST_H_
#define _BST_H_
class node
{
	public:
	node(int key = -1, int val = -1);
	node * left, * right, * next;
	int key;
	int val;
};


class BST
{
	public:
	BST();
	void insert(int key, int val = -1);
	node * insert(node * ptr, int key, int val);
	node * root;
};

void preorder(node *ptr);
void inorder(node *ptr);
void postorder(node *ptr);

#endif
