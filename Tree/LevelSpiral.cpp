#include <iostream>
#include "BST.h"
#include <stack>

using namespace std;

void LevelSpiral(node * ptr)
{
	if(ptr == NULL)
		return;
	stack<node *> S1;
	stack<node *> S2;
	bool first = true;
	S1.push(ptr);
	while(!S1.empty() || !S2.empty())
	{
		node *ptr = first?S1.top():S2.top();
		cout<<ptr->key<<" ";
		if(first)
		{
			if(ptr->right != NULL)
				S2.push(ptr->right);
			if(ptr->left != NULL)
				S2.push(ptr->left);
			S1.pop();
			if(S1.empty())
				first = false;
		}else
		{
			if(ptr->left != NULL)
				S1.push(ptr->left);
			if(ptr->right != NULL)
				S1.push(ptr->right);
			S2.pop();
			if(S2.empty())
				first = true;
		}
	}
}



int main()
{
	BST bst;
	bst.insert(50);bst.insert(21);bst.insert(74);bst.insert(10);bst.insert(35);
	bst.insert(60);bst.insert(5);bst.insert(15);bst.insert(40);bst.insert(65);
	bst.insert(95);bst.insert(1);bst.insert(36);bst.insert(39);bst.insert(80);bst.insert(79);bst.insert(78);bst.insert(77);
	LevelSpiral(bst.root);
	cout<<endl;
	return 0;
}
