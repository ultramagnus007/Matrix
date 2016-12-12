/*
Given a sequence, find the length of the longest palindromic subsequence in it.
For example, if the given sequence is “BBABCBCAB”,
then the output should be 7 as “BABCBAB” is the longest palindromic subseuqnce in it
*/
#include <iostream>
#include <cstring>
using namespace std;

int LPSS(char *a, int lo, int hi)
{
	if(lo >= hi)
		return lo==hi;
	if(a[lo] == a[hi])
		return 2+LPSS(a, lo+1, hi-1);
	return max(LPSS(a, lo+1, hi), LPSS(a, lo, hi-1));
}

int main()
{
	char s[] = "GEEKSFORGEEKS";
	cout<<LPSS(s, 0, strlen(s)-1)<<endl;
	return 0;
}
