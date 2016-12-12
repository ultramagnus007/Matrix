/*
Given an array of n positive integers. Write a program to find the sum of maximum sum subsequence of the given array such that the intgers in the subsequence are sorted in increasing order.
For example, if input is {1, 101, 2, 3, 100, 4, 5}, then output should be 106 (1 + 2 + 3 + 100)
if the input array is {3, 4, 5, 10}, then output should be 22 (3 + 4 + 5 + 10)
if the input array is {10, 5, 4, 3}, then output should be 10 
*/
#include <iostream>
#include <climits>
#include <vector>
using namespace std;


//Done Mistake
int MSS(const vector<int> &a, int i)
{
	int mss = a[i];
	for(int k = 0; k < i; k++)
	{
		if(a[k]<=a[i])
			mss = max(mss, a[i]+MSS(a, k));
	}
	return mss;		
}

int main()
{
	//vector<int> a = {1, 101, 2, 3, 100, 4, 5};
	//vector<int> a = {3, 4, 5, 10};
	vector<int> a = {10, 5, 4, 3};
	int mss = INT_MIN;
	for(int i = 0; i < a.size(); i++)
		mss = max(mss, MSS(a, i));
	cout<<mss<<endl;
	return 0;
}
