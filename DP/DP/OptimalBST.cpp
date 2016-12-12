/*
Given a sorted array keys[0.. n-1] of search keys and an array freq[0.. n-1] of frequency counts, where freq[i] is the number of searches to keys[i]. Construct a binary search tree of all keys such that the total cost of all the searches is as small as possible.
*/
#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int OptimalBST(const vector<int> &F)
{
	int N = F.size();
	vector<int> CC(N+1, 0);
	for(int i = 1; i <= N; i++)
		CC[i] = F[i-1]+CC[i-1];
	vector<vector<int>> table(N);
	for(auto &v: table)
		v.resize(N, INT_MAX);
	for(int i = 0; i < N; i++)
		table[i][i] = F[i];
	for(int gap = 1; gap < N; gap++)
	{
		for(int i = 0; i+gap < N; i++)
		{
			int lo = i;
			int hi = lo+gap;
			for(int k = lo; k <= hi; k++)
			{
				table[lo][hi] = min(table[lo][hi],
					 CC[hi+1]-CC[lo]+ (k-1>=lo?table[lo][k-1]:0)+(k+1<=hi?table[k+1][hi]:0));
			}
		}
	}
	return table[0][N-1];
}

int main()
{
	vector<int> K = {10, 12, 20};
	vector<int> F = {34, 8, 50};
        cout<<"Cost of Optimal BST is = "<<OptimalBST(F)<<endl;
        return 0;
}

