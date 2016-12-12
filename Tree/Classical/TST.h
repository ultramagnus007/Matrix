#ifndef _TST_H_
#define _TST_H_
#include <iostream>
#include <string>
using namespace std;

class node
{
	public:
	node(char key, int val = -1);
	char key;
	int val;
	node *left , *mid, *right;
};

class TST
{
	public:
	TST();
	void insert(string &str, int val);
	node * insert(node * ptr, int i, string &str, int val);
	int find(string &str);
	node * root;
};

#endif

