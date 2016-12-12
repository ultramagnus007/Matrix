/*
Given n dice each with m faces, numbered from 1 to m, find the number of ways to get sum X. X is the summation of values on each face when all the dice are thrown.
*/

#include <iostream>
#include <vector>
using namespace std;


int findWays(int m, int n, int X)
{
	vector<vector<int>> table(n+1);
	for(auto &v: table)
		v.resize(X+1, 0);
	table[0][0] = 1;

	for(int i = 1; i<= n; i++)
	{
		for(int j = 1; j <= X; j++)
		{
			for(int k = 1; k <= m && k <= j; k++)
			{
				table[i][j] += table[i-1][j-k];
			}
		}
	}
	return table[n][X];
}


int main()
{
    cout << findWays(4, 2, 1) << endl;
    cout << findWays(2, 2, 3) << endl;
    cout << findWays(6, 3, 8) << endl;
    cout << findWays(4, 2, 5) << endl;
    cout << findWays(4, 3, 5) << endl;
    return 0;
}

