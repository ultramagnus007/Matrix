//For Range minimum query
#include <iostream>
#include <climits>
#include <cstdlib>
#include <ctime>
#include <vector>
using namespace std;

class node
{
	public:
	node(int key = -1);
	node* left;
	node* right;
	int key;
	int lo;
	int hi;
};
node::node(int key)
{
	this->key = key;
	left = right = NULL;
	lo = hi = -1;
}

int minRange(const vector<int> &a, int i, int j)
{
	int ans = INT_MAX;
	for(int k = i; k<= j; k++)
		ans = min(ans, a[k]);
	return ans;
}

node * ContructTree(const vector<int> &a, int lo, int hi)
{
	if(lo > hi)
		return NULL;
	node * ptr = new node();
	ptr->lo = lo;
	ptr->hi = hi;
	if(lo == hi)
	{
		ptr->key = a[lo];
		return ptr;
	}
	int mid = (lo+hi)/2;
	node * p1 = ContructTree(a, lo, mid);
	node * p2 = ContructTree(a, mid+1, hi);
	ptr->key = min(p1->key, p2->key);
	ptr->left = p1;
	ptr->right = p2;
	return ptr;	
}


int RangeMinQ(node* ptr, int lo, int hi)
{
	if(ptr == NULL)
		return INT_MAX;
	if(lo <= ptr->lo && ptr->hi <= hi)
		return ptr->key;
	if(hi < ptr->lo || lo > ptr->hi)
		return INT_MAX;
	return min(RangeMinQ(ptr->left, lo, hi)	, RangeMinQ(ptr->right, lo, hi));
}

int main()
{
	int N  = 100;
	vector<int> a(N);
	srand(time(NULL));
	for(auto &x: a)
		x = rand()%100;
	node * root = ContructTree(a, 0, a.size()-1);
	for(int i = 0; i < a.size(); i++)
	{
		for(int j = i; j < a.size(); j++)
		{
			int m1 = minRange(a, i, j);
			int m2 = RangeMinQ(root, i, j);
			if(m1 != m2)		
			{
				cout<<"BAD: "<<i<<" "<<j<<endl;
				return 0;
			}
		}
	}
	cout<<"GOOD"<<endl;
	return 0;	
}
