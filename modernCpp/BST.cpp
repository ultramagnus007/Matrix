#include "BST.h"

node* BST::insert(node* ptr, int key, int val)
{
	if(ptr == NULL)
		return new node(key, val);
	if(key < ptr->key)
		ptr->left = insert(ptr->left, key, val);
	else if(key > ptr->key)
		ptr->right = insert(ptr->right, key, val);
	else
		ptr->val = val;
	return ptr;
}

void BST::insert(int key, int val)
{
	root = insert(root, key, val);
}

void preorder(node* ptr)
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
        BST bst;
        bst.insert(79);bst.insert(94);bst.insert(29);bst.insert(64);bst.insert(21);
        bst.insert(56);bst.insert(63);bst.insert(10);bst.insert(98);bst.insert(58);

        preorder(bst.root);
        cout<<endl;
        inorder(bst.root);
        cout<<endl;
        postorder(bst.root);
        cout<<endl;
        return 0;
}

