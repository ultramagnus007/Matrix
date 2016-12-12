/*
The longest Increasing Subsequence (LIS) problem is to find the length of the longest subsequence of a given sequence such that all elements of the subsequence are sorted in increasing order. For example, length of LIS for { 10, 22, 9, 33, 21, 50, 41, 60, 80 } is 6 and LIS is {10, 22, 33, 50, 60, 80}. 
*/
#include <iostream>
#include <vector>
using namespace std;

int LIS(const vector<int> &a, int i)
{
	int lis = 1;
	for(int k = 0; k < i; k++)
		lis = max(lis, (a[k]<=a[i])+LIS(a, k));
	return lis;
}

int main()
{
	vector<int> a ={10, 22, 9, 33, 21, 50, 41, 60, 80}; 
	cout<<LIS(a, a.size()-1)<<endl;
	return 0;
}
