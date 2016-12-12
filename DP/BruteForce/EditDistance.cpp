/*
Given two strings of size m, n and set of operations replace (R), insert (I) and delete (D) all at equal cost. Find minimum number of edits 
(operations) required to convert one string into another.
*/
#include <iostream>
#include <cstring>
using namespace std;

int EditDistance(char *a, char *b, int i, int j)
{
	if(i < 0 && j < 0)
		return 0;
	if(i < 0)
		return j+1;
	if(j < 0)
		return i+1;
	if(a[i] == b[j])
		return EditDistance(a, b, i-1, j-1);
	else
		return 1+min(EditDistance(a, b, i-1, j-1), min(EditDistance(a, b, i-1, j), EditDistance(a, b, i, j-1)));
}

int main()
{
        char a[] = "SUNDAY";
        char b[] = "SATURDAY";
	int N1 = strlen(a);
	int N2 = strlen(b);
        cout<<EditDistance(a, b, N1-1, N2-1)<<endl;
	return 0;
}
