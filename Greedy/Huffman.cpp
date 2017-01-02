#include <iostream>
#include <vector>
#include <queue>
using namespace std;


class node
{
	public:
	node(int key, char ch = '\0');
	char ch;
	node *left, *right;
	int key;
};

node::node(int key, char ch)
{
	left = right = NULL;
	this->ch = ch;
	this->key = key;
}

class Compare
{
	public:
	bool operator()(const node *p1, const node * p2) const
	{
		return p1->key > p2->key;
	}
};


void Traverse(node * ptr, vector<char> &str)
{
	if(ptr == NULL)
		return;
	if(ptr->ch != '\0')
	{
		cout<<ptr->ch<<" : ";
		for(auto ch: str)
			cout<<ch;
		cout<<endl;
		return;
	}
	str.push_back('0');
	Traverse(ptr->left, str);
	str.pop_back();
	str.push_back('1');
	Traverse(ptr->right, str);
	str.pop_back();
}
int main()
{
	vector<char> a = {'a', 'b', 'c', 'd', 'e', 'f'};
	vector<int> freq = {5, 9, 12, 13, 16, 45};
	priority_queue<node *, vector<node*>, Compare> pq;
	for(int i = 0; i < a.size(); i++)
		pq.push(new node(freq[i], a[i]));
	while(pq.size() > 1)
	{
		node * p1 = pq.top();
		pq.pop();
		node * p2 = pq.top();
		pq.pop();
		node * ptr = new node(p1->key+p2->key);
		if(p1->key < p2->key)
		{
			ptr->left = p1;
			ptr->right = p2;
		}else
		{
			ptr->left = p2;
			ptr->right = p1;
		}
		pq.push(ptr);
	}
	node * root = pq.top();
	vector<char> str;
	Traverse(root, str);
}
