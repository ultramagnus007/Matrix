#include <iostream>
using namespace std;

class node
{
	public:
	node(int key);
	int key;
	node * next;
};
node::node(int key)
{
	next = NULL;
	this->key = key;
}

class List
{
	public:
	List();
	~List();
	void insert(int key);
	void print();
	void reverse();
	node * head;
	int size;
};

void List::reverse()
{
	if(head == NULL)
		return;
	node * p1 = head;
	node * p2 = head->next;
	p1->next = NULL;
	node * p3;
	while(p2 != NULL)
	{
		p3 = p2->next;
		p2->next =p1;
		p1 = p2;
		p2 = p3;
	}
	head = p1;
}

List::List()
{
	head = NULL;
	size = 0;
}
List::~List()
{
	node * ptr;
	while(head != NULL)
	{
		ptr =  head;
		head = head->next;
		delete ptr;
	}
}
void List::insert(int key)
{
	node * ptr = new node(key);
	ptr->next = head;
	head = ptr;
	size++;
}
void List::print()
{
	node * ptr = head;
	while(ptr != NULL)
	{
		cout<<ptr->key<<" ";
		ptr = ptr->next;
	}
	cout<<endl;
}

node * add(node *p1, node *p2, int N1, int N2)
{
	if(p1 == NULL || p2 == NULL)
		return NULL;
	int key = 0;
	node * nextp1, *nextp2;
	if(N1 > N2)
	{
		N1--;
		nextp1 = p1->next;
		nextp2 = p2;
		key = p1->key;
	}
	else if(N2 > N1)
	{
		N2--;
		nextp1 = p1;
		nextp2 = p2->next;
		key = p2->key;
	}
	else
	{
		N1--;
		N2--;
		nextp1 = p1->next;
		nextp2 = p2->next;
		key = p1->key+p2->key;
	}
	node * next = add(nextp1, nextp2, N1, N2);
	if(next != NULL && next->key >= 10)
	{
		key+=next->key/10;
		next->key = next->key%10;
	}
	node * ptr = new node(key);
	ptr->next = next;
	return ptr;
}

void add(List &L1, List &L2, List &L3)
{
	node * p1 = L1.head;
	node * p2 = L2.head;
	node * head = add(p1, p2, L1.size, L2.size);
	if(head->key >= 10)
	{
		node *ptr = new node(head->key/10);
		head->key = head->key%10;
		ptr->next = head;
		head = ptr;
	}
	L3.head = head;
}

int main()
{
	List L1;
	L1.insert(5);L1.insert(7);L1.insert(2);L1.insert(9);L1.insert(9);L1.insert(9);
	List L2;
	L2.insert(8);L2.insert(6);L2.insert(9);
	List L3;
	add(L1, L2, L3);
	L1.print();
	L2.print();
	L3.print();

	List L4;
	L1.reverse();
	L2.reverse();
	node * p1 = L1.head;
	node * p2 = L2.head;
	int carry = 0;
	while(p1 != NULL && p2 != NULL)
	{
		int key = p1->key+p2->key+carry;
		carry = key/10;
		key = key%10;
		L4.insert(key);
		p1 = p1->next;
		p2 = p2->next;
	}
	while(p1 != NULL)
	{
		int key = p1->key+carry;
		carry = key/10;
		key = key%10;
		L4.insert(key);
		p1 = p1->next;
	}
	while(p2 != NULL)
	{
		int key = p2->key+carry;
		carry = key/10;
		key = key%10;
		L4.insert(key);
		p2 = p2->next;
	}
	if(carry != 0)
		L4.insert(carry);
	L1.reverse();
	L2.reverse();
	L4.print();
};
