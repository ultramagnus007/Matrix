/*
Given a sorted array keys[0.. n-1] of search keys and an array freq[0.. n-1] of frequency counts, where freq[i] is the number of searches to keys[i]. Construct a binary search tree of all keys such that the total cost of all the searches is as small as possible.
*/

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int sum(const vector<int> &F, int lo, int hi)
{
	int sum = 0;
	for(int i = lo; i <= hi; i++)
		sum+=F[i];
	return sum;
}	


int OptimalBST(const vector<int> &F, int lo, int hi)
{
	if(lo>hi)
		return 0;
	int s = sum(F, lo, hi);
	int mincost = INT_MAX;
	for(int i = lo; i <= hi; i++)
		mincost = min(mincost, s+OptimalBST(F, lo, i-1)+OptimalBST(F, i+1, hi));
	return mincost;
}
int OptimalBST_1(const vector<int> &F, int lo, int hi, int level)
{
	if(lo>hi)
		return 0;
	int mincost = INT_MAX;
	for(int i = lo; i <= hi; i++)
		mincost = min(mincost, level*F[i]+OptimalBST_1(F, lo, i-1, level+1)+OptimalBST_1(F, i+1, hi, level+1));
	return mincost;
}
int main()
{
	vector<int> K = {10, 12, 20};
	vector<int> F = {34, 8, 50};

	cout<<OptimalBST(F, 0, K.size()-1)<<endl;
	cout<<OptimalBST_1(F, 0, K.size()-1, 1)<<endl;

	return 0;
}
