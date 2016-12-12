/*
Given weights and values of n items, put these items in a knapsack of capacity W to get the maximum total value in the knapsack. 
*/

#include <iostream>
#include <vector>
using namespace std;


int Knapsack(const vector<int> &V, const vector<int> &W, int C)
{
	int N = V.size();
	vector<vector<int>> table(N+1);
	for(auto &v: table)
		v.resize(C+1, 0);
	for(int i = 1; i <= N; i++)
	{
		for(int j = 1; j <= C; j++)
		{
			if(j-W[i-1] >= 0)
			table[i][j] = max(table[i-1][j], V[i-1]+table[i-1][j-W[i-1]]);
			else
			table[i][j] = table[i-1][j];
		}
	}
	return table[N][C];
}

int main()
{
	vector<int> V = {60, 100, 120};
	vector<int> W = {10, 20, 30};
	const int  C = 50;
        cout<<Knapsack(V, W, C)<<endl;
        return 0;
}
