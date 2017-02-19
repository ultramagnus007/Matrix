#include <iostream>
#include <vector>
#include <string>
using namespace std;

class node
{
	public:
	node(char key = '\0', int val = 0);
	node *left, *mid, *right;
	char key;
	int val;
};

node::node(char key, int val)
{
	left = mid = right = NULL;
	this->key = key;
	this->val = val;
}

class TST
{
	public:
	TST(){root = NULL;}
	void insert(const string& str, int val = -1);
	int find(const string& str);
	private:
	node * insert(node* ptr, const string& str, int i, int val);
	node * root;
};

void TST::insert(const string& str, int val)
{
	if(str.size() == 0)
		return;
	root = insert(root, str, 0, val);
}

node * TST::insert(node* ptr, const string& str, int i, int val)
{
	if(ptr == NULL)
		ptr = new node(str[i]);
	if(i == str.size()-1)
	{
		ptr->val = val;
		return ptr;
	}
	if(str[i] < ptr->key)
		ptr->left = insert(ptr->left, str, i, val);
	else if(str[i] == ptr->key)
		ptr->mid = insert(ptr->mid, str, i+1, val);
	else
		ptr->right = insert(ptr->right, str, i, val);
	return ptr;
}

int TST::find(const string& str)
{
	int i = 0;
	node * ptr = root;
	while(i != str.size() && ptr != NULL)
	{
		if(ptr->key < str[i])
			ptr = ptr->right;
		else if(ptr->key > str[i])
			ptr = ptr->left;
		else
		{
			i++;
			if(i == str.size())
				return ptr->val;
			ptr  = ptr->mid;
		}
	}
	return -1;
}

int main()
{
	TST T;
	vector<string>a = {"amit", "anil", "nittin", "alonso", "kimi", "raikkonen"};
	for(int i = 0 ; i < a.size(); i++)
		T.insert(a[i], (i+1)*(i+1));
	for(int i = 0; i < a.size(); i++)
		cout<<T.find(a[i])<<" "<<a[i]<<endl;
	cout<<T.find("amitasdasdddd")<<endl;
	cout<<T.find("unsu")<<endl;
	return 0;
}

