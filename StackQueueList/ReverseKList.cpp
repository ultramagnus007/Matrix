/*
Given a linked list, write a function to reverse every k nodes (where k is an input to the function).

Example:
Inputs:  1->2->3->4->5->6->7->8->NULL and k = 3 
Output:  3->2->1->6->5->4->8->7->NULL. 

Inputs:   1->2->3->4->5->6->7->80->NULL and k = 5
Output:  5->4->3->2->1->8->7->6->NULL. 
*/
#include <iostream>
using namespace std;

class node
{
	public:
	node(int key){this->key = key;}
	node * next;
	int key;
};

node * makeList(int N)
{
	if(N == 0)
		return NULL;
	node * head = new node(1);
	node * ptr = head;
	for(int i = 2; i <= N; i++)
	{
		ptr->next = new node(i);
		ptr = ptr->next;
	}
	return head;
}
void printList(node * ptr)
{
	while(ptr!= NULL)
	{
		cout<<ptr->key<<" ";
		ptr = ptr->next;
	}
	cout<<endl;
}	



pair<node *, node *> Reverse(node * ptr, int K)
{
	pair<node*, node*> P(NULL, NULL);
	if(ptr == NULL)
		return P;
	node * pre = NULL;
	node * cur = ptr;
	node * next = NULL;
	while(cur != NULL && K > 0)
	{
		next = cur->next;
		cur->next = pre;
		pre = cur;
		cur = next;
		K--;
	}
	P.first = pre;
	P.second = cur;
	return P;
}

node * reverseK(node *ptr, int K)
{
	node * p1 = NULL;
	node * p2 = ptr;
	node * head = NULL;
	while(p2 != NULL)
	{

		pair<node *, node *> P = Reverse(p2, K);
		node * p3 = P.first;
		node * p4 = P.second;
		
		if(head == NULL)
			head = p3;
		else
			p1->next = p3;
		p1 = p2;
		p2 = p4;
	}
	return head;
}


int main()
{
	int N, K;
	cout<<"Enter N and K\n";
	cin>>N>>K;
	node * ptr = makeList(N);
	ptr = reverseK(ptr, K);
	printList(ptr);
	return 0;
}
