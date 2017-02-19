#include <iostream>
using namespace std;

class node
{
	public:
	node(int key , int val = -1);
	node *left, *right;
	int key, val;
	int h, bal;
	int cal();
};

node::node(int key , int val)
{
	this->key = key;
	this->val = val;
	left = right = NULL;
	h = 0;
	bal = 0;
}
int node::cal()
{
	int lh = (left==NULL)?0:left->h+1;
	int rh = (right==NULL)?0:right->h+1;
	h = max(lh, rh);
	bal = rh-lh;
}

node* rotateLeft(node *ptr)
{
	if(ptr == NULL || ptr->right == NULL)
		return NULL;
	node * R = ptr->right;
	ptr->right = R->left;
	ptr->cal();
	R->left = ptr;
	R->cal();
	return R;
}

node* rotateRight(node *ptr)
{
	if(ptr == NULL || ptr->left == NULL)
		return NULL;
	node *L = ptr->left;
	ptr->left = L->right;
	ptr->cal();
	L->right = ptr;
	L->cal();
	return L;
}


class AVL
{
	private:
	node* insert(node* ptr, int key, int val);
	public:
	node *root;
	AVL();
	void insert(int key, int val = -1);
};

AVL::AVL()
{
	root = NULL;
}

void AVL::insert(int key, int val)
{
	root = insert(root, key, val);
}

node* AVL::insert(node* ptr, int key, int val)
{
	if(ptr == NULL)
		return new node(key, val);
	if(key < ptr->key)
		ptr->left = insert(ptr->left, key, val);
	else if(key > ptr->key)
	{
		ptr->right = insert(ptr->right, key, val);
	}
	else
		ptr->val = val;
	ptr->cal();
	if(ptr->bal == -2)
	{
		if(ptr->left->bal == 1)
			ptr->left = rotateLeft(ptr->left);
		ptr = rotateRight(ptr);
	}
	else if(ptr->bal == 2)
	{
		if(ptr->right->bal == -1)
			ptr->right = rotateRight(ptr->right);
		ptr = rotateLeft(ptr);
	}
	return ptr;
}

void preorder(node * ptr)
{
	if(ptr == NULL)
		return;
	cout<<ptr->key<<" ";
	preorder(ptr->left);
	preorder(ptr->right);
}

void inorder(node * ptr)
{
	if(ptr == NULL)
		return;
	inorder(ptr->left);
	cout<<ptr->key<<" ";
	inorder(ptr->right);
}

void postorder(node * ptr)
{
	if(ptr == NULL)
		return;
	postorder(ptr->left);
	postorder(ptr->right);
	cout<<ptr->key<<" ";
}



int main()
{
	AVL avl;
	avl.insert(79);avl.insert(94);avl.insert(29);avl.insert(64);avl.insert(21);
	avl.insert(56);avl.insert(63);avl.insert(10);avl.insert(98);avl.insert(58);

	preorder(avl.root);
	cout<<endl;
	inorder(avl.root);
	cout<<endl;
	postorder(avl.root);
	cout<<endl;
	return 0;
}
