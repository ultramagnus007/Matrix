/*
Longest Bitonic Subsequence
Given an array arr[0 ... n-1] containing n positive integers, a subsequence of arr[] is called Bitonic if it is first increasing, then decreasing. Write a function that takes an array as argument and returns the length of the longest bitonic subsequence.
A sequence, sorted in increasing order is considered Bitonic with the decreasing part as empty. Similarly, decreasing order sequence is considered Bitonic with the increasing part as empty.

Examples:

Input arr[] = {1, 11, 2, 10, 4, 5, 2, 1};
Output: 6 (A Longest Bitonic Subsequence of length 6 is 1, 2, 10, 4, 2, 1)

Input arr[] = {12, 11, 40, 5, 3, 1}
Output: 5 (A Longest Bitonic Subsequence of length 5 is 12, 11, 5, 3, 1)

Input arr[] = {80, 60, 30, 40, 20, 10}
Output: 5 (A Longest Bitonic Subsequence of length 5 is 80, 60, 30, 20, 10)
*/
#include <iostream>
#include <vector>
using namespace std;

int BitonicSS(vector<int> &a)
{
	int bitss = 1;
	vector<int> LIS(a.size(), 1);
	vector<int> LDS(a.size(), 1);
	for(int i = 0; i < a.size(); i++)
	{
		for(int j = 0; j < i; j++)
		{
		if(a[j] <= a[i])
			LIS[i] = max(LIS[i], LIS[j]+1);
		}
	}
	for(int i = a.size()-1; i >= 0; i--)
	{
		for(int j = a.size()-1; j > i; j--)
		{
		if(a[j] <= a[i])
			LDS[i] = max(LDS[i], LDS[j]+1);
		}
	}
	for(int i = 0; i < a.size(); i++)
		bitss = max(bitss, LIS[i]+LDS[i]-1);
	return bitss;
}

int main()
{
	vector<int> a1 = {1, 11, 2, 10, 4, 5, 2, 1};
	vector<int> a2 = {12, 11, 40, 5, 3, 1};
	vector<int> a3 = {80, 60, 30, 40, 20, 10};
	cout<<BitonicSS(a1)<<endl;
	cout<<BitonicSS(a2)<<endl;
	cout<<BitonicSS(a3)<<endl;
	return 0;
}
