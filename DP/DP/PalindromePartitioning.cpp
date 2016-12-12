/*
Given a string, a partitioning of the string is a palindrome partitioning if every substring of the partition is a palindrome. For example, “aba|b|bbabb|a|b|aba” is a palindrome partitioning of “ababbbabbababa”. Determine the fewest cuts needed for palindrome partitioning of a given string. For example, minimum 3 cuts are needed for “ababbbabbababa”. The three cuts are “a|babbbab|b|ababa”. If a string is palindrome, then minimum 0 cuts are needed. If a string of length n containing all different characters, then minimum n-1 cuts are needed.
*/

#include <iostream>
#include <vector>
#include <cstring>
using namespace std;


int PalinPartition(const char *a)
{
	int N = strlen(a);

	vector<vector<bool>> palin(N);
	for(auto &v: palin)
		v.resize(N, false);
	for(int i = 0; i < N; i++)
		palin[i][i] = true;

	vector<vector<int>> cuts(N);
	for(auto &v: cuts)
		v.resize(N, 0);

	for(int gap = 1; gap < N; gap++)
	{
		for(int i = 0; i+gap < N; i++)
		{
			int lo = i;
			int hi = i+gap;
			if(a[lo]==a[hi])
				palin[lo][hi] = hi-lo > 1?palin[lo+1][hi-1]:true;
			if(palin[lo][hi])
			{
				cuts[lo][hi] = 0;
				continue;
			}
			int mincuts = hi-lo;
			for(int k = lo; k < hi; k++)
				mincuts = min(mincuts, 1+cuts[lo][k]+cuts[k+1][hi]);
			cuts[lo][hi] = mincuts;
		}
	}
	return cuts[0][N-1];
}

int main()
{
        char a[] = "ababbbabbababa";
        char b[] = "abcdefgh";
        cout<<PalinPartition(a)<<endl;
        cout<<PalinPartition(b)<<endl;
	return 0;
}
