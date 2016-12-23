#include <iostream>
#include <stack>
#include "BST.h"
using namespace std;


void preorderStack(node *ptr)
{
	if(ptr == NULL)
		return;
	stack<node *> S;
	S.push(ptr);
	while(!S.empty())
	{
		ptr = S.top();
		S.pop();
		cout<<ptr->key<<" ";
		if(ptr->right != NULL)
			S.push(ptr->right);
		if(ptr->left != NULL)
			S.push(ptr->left);
	}
	cout<<endl;
}

void inorderStack(node * ptr)
{
	if(ptr == NULL)
		return;
	stack<node *> S;
	S.push(ptr)
	while()
	{
		ptr = S.top();
		if(ptr->right != NULL)
		{
			if(!(S.empty() || S.top()==ptr->right))
					S.push(ptr->right);
		}
		if()
	}
	cout<<endl;
}

int main()
{
    BST bst;
    #if 0
    srand(time(NULL));
    for(int i = 0; i < 100; i++)
        bst.insert(rand()%100);
    #else
    bst.insert(84);bst.insert(75);bst.insert(49);bst.insert(15);bst.insert(92);
    bst.insert(59);bst.insert(27);bst.insert(38);bst.insert(55);bst.insert(62);
    #endif
    preorder(bst.root);
    cout<<endl;
    preorderStack(bst.root);

    cout<<endl;
    inorder(bst.root);
    cout<<endl;
    inorderStack(bst.root);
    cout<<endl;
    return 0;
}
