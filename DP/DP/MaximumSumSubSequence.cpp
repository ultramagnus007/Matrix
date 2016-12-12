/*
Given an array of n positive integers. Write a program to find the sum of maximum sum subsequence of the given array such that the intgers in the subsequence are sorted in increasing order.
For example, if input is {1, 101, 2, 3, 100, 4, 5}, then output should be 106 (1 + 2 + 3 + 100)
if the input array is {3, 4, 5, 10}, then output should be 22 (3 + 4 + 5 + 10)
if the input array is {10, 5, 4, 3}, then output should be 10 
*/


#include <iostream>
#include <vector>
using namespace std;

int MSS(const vector<int> &a)
{
	vector<int> table(a.size(), 0);
	int mss = 0;
	for(int i = 0; i < a.size(); i++)
	{
		table[i] = a[i];
		for(int j = 0; j < i; j++)
			if(a[i] >= a[j])
				table[i] = max(table[i], a[i]+table[j]);
		mss = max(mss, table[i]);
	}
	return mss;
}


int main()
{
	vector<int> a1 = {1, 101, 2, 3, 100, 4, 5};
	vector<int> a2 = {3, 4, 5, 10};
	vector<int> a3 = {10, 5, 4, 3};
	cout<<MSS(a1)<<endl;
	cout<<MSS(a2)<<endl;
	cout<<MSS(a3)<<endl;
	return 0;
}
