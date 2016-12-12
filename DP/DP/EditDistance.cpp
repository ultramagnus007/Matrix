/*
Given two strings of size m, n and set of operations replace (R), insert (I) and delete (D) all at equal cost. Find minimum number of edits 
(operations) required to convert one string into another.
*/
#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int EditDistance(const char *a, const char *b)
{
	int N1 = strlen(a);
	int N2 = strlen(b);
	vector<vector<int>> table(N1+1);
	for(auto &v: table)
		v.resize(N2+1, 0);
	for(int i = 1; i <= N1; i++)
		table[i][0] = i;
	for(int j = 1; j <= N2; j++)
		table[0][j] = j;
	for(int i = 1; i <= N1; i++)
	{
		for(int j = 1; j<= N2; j++)
		{
			if(a[i-1] == b[j-1])
			table[i][j] = table[i-1][j-1];
			else
			table[i][j] = 1+min(table[i-1][j-1], min(table[i-1][j], table[i][j-1]));
		}
	}
	return table[N1][N2];
}

int main()
{
        char a[] = "SUNDAY";
        char b[] = "SATURDAY";
        cout<<EditDistance(a, b)<<endl;
        return 0;
}
