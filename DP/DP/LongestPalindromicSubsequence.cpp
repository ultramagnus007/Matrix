/*
Given a sequence, find the length of the longest palindromic subsequence in it.
For example, if the given sequence is “BBABCBCAB”,
then the output should be 7 as “BABCBAB” is the longest palindromic subseuqnce in it
*/

#include <iostream>
#include <vector>
#include <cstring>
using namespace std;


int LPSUB(const char *a)
{
	int N = strlen(a);
	vector<vector<int>> table(N);
	for(auto &v: table)
		v.resize(N, 1);
	for(int gap = 1; gap < N; gap++)
	{
		for(int i = 0; i+gap < N; i++)
		{
			int lo = i;
			int hi = i+gap;
			if(a[hi] == a[lo])
			table[lo][hi] = 2+ ((hi-lo>1)?table[lo+1][hi-1]:0);
			else
			table[lo][hi] = max(table[lo+1][hi], table[lo][hi-1]);
		}	
	}
	return table[0][N-1];
}

int main()
{
        char a1[] = "GEEKSFORGEEKS";
        char a2[] = "BBABCBCAB";
        cout<<LPSUB(a1)<<endl;
        cout<<LPSUB(a2)<<endl;
        return 0;
}

