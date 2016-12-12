/*
Given a string, a partitioning of the string is a palindrome partitioning if every substring of the partition is a palindrome. For example, “aba|b|bbabb|a|b|aba” is a palindrome partitioning of “ababbbabbababa”. Determine the fewest cuts needed for palindrome partitioning of a given string. For example, minimum 3 cuts are needed for “ababbbabbababa”. The three cuts are “a|babbbab|b|ababa”. If a string is palindrome, then minimum 0 cuts are needed. If a string of length n containing all different characters, then minimum n-1 cuts are needed.
*/
#include <iostream>
#include <cstring>
#include <climits>
using namespace std;


bool isPalin(char *a, int lo, int hi)
{
	while(lo < hi)
	{
		if(a[lo] != a[hi])
			return false;
		lo++,hi--;
	}
	return true;
}

int PalinPar(char *a, int lo, int hi)
{
	if(isPalin(a, lo, hi))
		return 0;
	int mincut = hi-lo-1;
	for(int i = lo; i < hi; i++)
		mincut = min(mincut, 1+PalinPar(a, lo, i)+PalinPar(a, i+1, hi));
	return mincut;
}

int main()
{
        char a[] = "ababbbabbababa";
	cout<<PalinPar(a, 0, strlen(a)-1)<<endl;
	return 0;
}
