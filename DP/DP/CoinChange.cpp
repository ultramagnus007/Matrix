/*
Given a value N, if we want to make change for N cents, and we have infinite supply of each of S = { S1, S2, .. , Sm} valued coins, how many ways can we make the change? The order of coins doesn’t matter.

For example, for N = 4 and S = {1,2,3}, there are four solutions: {1,1,1,1},{1,1,2},{2,2},{1,3}. So output should be 4. For N = 10 and S = {2, 5, 3, 6}, there are five solutions: {2,2,2,2,2}, {2,2,3,3}, {2,2,6}, {2,3,5} and {5,5}. So the output should be 5.
*/
#include <iostream>
#include <vector>
using namespace std;


int CoinChange(const vector<int> &a, int S)
{
	int N = a.size();
	vector<vector<int>> table(N+1);
	for(auto &v: table)
		v.resize(S+1, 0);
	for(int i = 0; i <= N; i++)
		table[i][0] = 1;
	for(int i = 1; i <= N; i++)
	{
		for(int j = 1; j <= S; j++)
		{
			if(j-a[i-1] >= 0)
			table[i][j] = table[i-1][j] + table[i][j-a[i-1]];
			else
			table[i][j] = table[i-1][j];
		}
	}
	return table[N][S];
}
int main()
{
        vector<int> a1 = {1, 2, 3};
        int S1 = 4;
        vector<int> a2 = {2, 5, 3, 6};
        int S2 = 10;
        cout<<CoinChange(a1, S1)<<endl;
        cout<<CoinChange(a2, S2)<<endl;
        return 0;
}

