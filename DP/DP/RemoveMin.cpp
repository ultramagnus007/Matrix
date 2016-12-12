/*
Remove minimum elements from either side such that 2*min becomes more than max

Given an unsorted array, trim the array such that twice of minimum is greater than maximum in the trimmed array. Elements should be removed either end of the array.

Number of removals should be minimum.

Examples:

arr[] = {4, 5, 100, 9, 10, 11, 12, 15, 200}
Output: 4
We need to remove 4 elements (4, 5, 100, 200)
so that 2*min becomes more than max.


arr[] = {4, 7, 5, 6}
Output: 0
We don't need to remove any element as 
4*2 > 7 (Note that min = 4, max = 8)

arr[] = {20, 7, 5, 6}
Output: 1
We need to remove 20 so that 2*min becomes
more than max

arr[] = {20, 4, 1, 3}
Output: 3
We need to remove any three elements from ends
like 20, 4, 1 or 4, 1, 3 or 20, 3, 1 or 20, 4, 1
*/
#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

int RemoveMin(const vector<int> &a)
{
	int N = a.size();
	vector<vector<int>> MIN(N);
	vector<vector<int>> MAX(N);
	for(auto &v: MIN)
		v.resize(N, INT_MAX);
	for(auto &v: MAX)
		v.resize(N, INT_MIN);
	for(int i = 0; i < N; i++)
	{
		MIN[i][i] = a[i];
		MAX[i][i] = a[i];
	}
	for(int gap = 1; gap < N; gap++)
	{
		for(int i = 0; i+gap < N; i++)
		{
			int lo = i;
			int hi = lo+gap;
			MIN[lo][hi] = min(MIN[lo+1][hi], MIN[lo][hi-1]);
			MAX[lo][hi] = max(MAX[lo+1][hi], MAX[lo][hi-1]);
		}
	}
	for(int gap = N-1; gap > 0; gap--)
	{
		for(int i = 0; i+gap < N; i++)
		{
			int lo = i;
			int hi = lo+gap;
			if(MAX[lo][hi] < 2*MIN[lo][hi])
				return N-gap-1;
		}
	}
	return N-1;
}

int main()
{
        vector<int> a1 = {4, 5, 100, 9, 10, 11, 12, 15, 101,102,103,104,105,106,107,108,109,110,111,112};
        vector<int> a2 = {20, 4, 1, 3};
	vector<int> a3 = {4, 5, 100, 9, 10, 11, 12, 15, 200};
	vector<int> a4 = {20, 7, 5, 6};
	vector<int> a5 = {4, 7, 5, 6};
        cout<<RemoveMin(a1)<<endl;
        cout<<RemoveMin(a2)<<endl;
        cout<<RemoveMin(a3)<<endl;
        cout<<RemoveMin(a4)<<endl;
        cout<<RemoveMin(a5)<<endl;
        return 0;
}


