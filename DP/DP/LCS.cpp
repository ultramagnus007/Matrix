/*
LCS Problem Statement: Given two sequences, find the length of longest subsequence present in both of them. A subsequence is a sequence that appears in the same relative order, but not necessarily contiguous. 
*/
#include <iostream>
#include <vector>
#include <cstring>
using namespace std;


int LCS(const char *a, const char *b)
{
	int N1 = strlen(a);
	int N2 = strlen(b);
	vector<vector<int>> table(N1+1);
	for(auto &v: table)
		v.resize(N2+1, 0);

	for(int i = 1; i <= N1; i++)
	{
		for(int j = 1; j <= N2; j++)
		{
			if(a[i-1] == b[j-1])
			table[i][j] = table[i-1][j-1] + 1;
			else
			table[i][j] = max(table[i-1][j], table[i][j-1]);
		}
	}
	return table[N1][N2];
}


int main()
{
        #if 0
        char a[] = "AGGTAB";
        char b[] = "GXTXAYB";
        #else
        char a[] = "ABCDGH";
        char b[] = "AEDFHR";
        #endif
        cout<<LCS(a, b)<<endl;
        return 0;
}
