#include "TST.h"
#include <iostream>
#include <vector>
using namespace std;

node::node(char key, int val)
{
	this->key = key;
	this->val = val;
	left = mid = right = NULL;
}

TST::TST()
{
	root = NULL;
}

void TST::insert(string &str, int val)
{	
	root = insert(root, 0, str, val);
}


node * TST::insert(node * ptr, int i, string &str, int val)
{
	if(i == str.length())
		return ptr;
	if(ptr == NULL)
	{
		if(i+1 == str.length())
			ptr = new node(str[i], val);	
		else
			ptr = new node(str[i]);	
	}else
	{
		if(ptr->val == -1 && i+1 == str.length())
			ptr->val = val;
	}


	if(ptr->key == str[i])
		ptr->mid = insert(ptr->mid, i+1, str, val);
	else if(str[i] < ptr->key)
		ptr->left = insert(ptr->left, i, str, val);
	else
		ptr->right = insert(ptr->right, i, str, val);
	return ptr;
}

int TST::find(string &str)
{
	int i = 0;
	node * ptr = root;
	node * preptr = NULL;
	while(ptr != NULL && i != str.length())
	{
		if(ptr->key == str[i])
		{
			preptr = ptr;
			ptr = ptr->mid;
			i++;
		}
		else if(str[i] < ptr->key)
			ptr = ptr->left; 
		else
			ptr = ptr->right;
	}
	if(i == str.length() && preptr != NULL)
		return preptr->val;
	else
		return -1;
}


#if 0
int main()
{
        TST T;
        vector<string> a = {"amit", "anil", "nittin", "alonso", "kimi", "raikkonen"};
        int n = a.size();
        for(int i = 0; i < n; i++)
                T.insert(a[i], (i+1)*(i+1));
        for(int i = 0; i < n; i++)
                cout<<a[i]<<" "<<T.find(a[i])<<endl;
        cout<<endl;
	string s("unsu");
        cout<<"unsu = "<<T.find(s)<<endl;
	return 0;
}
#endif
