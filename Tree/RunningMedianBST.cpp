#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;


void insertionSort(vector<int> &a)
{
	for(int i = a.size()-1; i > 0; i--)
	{
		if(a[i] < a[i-1])
			swap(a[i], a[i-1]);
		else
			break;
	}
}

float getMedian(const vector<int> &a)
{
	int N = a.size();
	if(N==0)
		return 0;
	if(N%2 == 1)
		return a[N/2];
	else
		return a[N/2]/2.0+a[N/2-1]/2.0;
}
class node
{
	public:
	node(int key);
	node * left, * right;
	int key;
	int size;
};

node::node(int key)
{
	left = right = NULL;
	this->key = key;
	size = 1;
}

class BST
{
	private:
	node * insert(node * ptr, int key);
	int kthKey(node * ptr, int k);
	public:
	BST();
	void insert(int key);
	int kthKey(int k);
	node * root;
};

int BST::kthKey(int k)
{
	return kthKey(root, k);
}

int BST::kthKey(node *ptr, int k)
{
	if(ptr == NULL)
	{
		cout<<"NULL Pointer"<<endl;
		return 0;
	}
	int rank = (ptr->left!=NULL)? ptr->left->size+1:1;
	if(k == rank)
		return ptr->key;
	if(k < rank)
		return kthKey(ptr->left, k);
	return kthKey(ptr->right, k-rank);
}

BST::BST()
{
	root = NULL;
}	
void BST::insert(int key)
{
	root = insert(root, key);
}

node * BST::insert(node * ptr, int key)
{
	if(ptr == NULL)
		return new node(key);
	if(ptr->key > key)
		ptr->left = insert(ptr->left, key);
	else
		ptr->right = insert(ptr->right, key);
	ptr->size+=1;
	return ptr;
}

void inorder(node * ptr)
{
	if(ptr == NULL)
		return;
	inorder(ptr->left);
	cout<<ptr->key<<" ";
	inorder(ptr->right);
}
int main()
{
	vector<int> a;
	int N = 1000;
	BST bst;
	srand(time(NULL));
	while(N-- > 0)
	{
		int x = rand()%100;
		a.push_back(x);
		bst.insert(x);
		insertionSort(a);
		float median = 0;
		if(a.size()%2 == 1)
			median = bst.kthKey((a.size()+1)/2);
		else
			median = bst.kthKey(a.size()/2)/2.0 +bst.kthKey(a.size()/2+1)/2.0;
		if(median != getMedian(a))
		{
			inorder(bst.root);
			cout<<endl;
			cout<<median<<" "<<getMedian(a)<<" "<<a.size()<<endl;
			cout<<"Bad"<<endl;
			return 0;
		}
	}
	cout<<"Good"<<endl;
	return 0;
}
