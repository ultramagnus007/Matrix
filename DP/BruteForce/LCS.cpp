/*
LCS Problem Statement: Given two sequences, find the length of longest subsequence present in both of them. A subsequence is a sequence that appears in the same relative order, but not necessarily contiguous. 
*/
#include <iostream>
#include <cstring>
using namespace std;


int LCS(char *a, char *b, int i, int j)
{
	if(i<0 || j<0)
		return 0;
	if(a[i] == b[j])
		return 1+LCS(a, b, i-1, j-1);
	else
		return max(LCS(a, b, i-1, j), LCS(a, b, i, j-1));
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
        int N1 = strlen(a);
        int N2 = strlen(b);
	cout<<LCS(a, b, N1-1, N2-1)<<endl;
	return 0;
}
