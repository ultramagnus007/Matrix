/*
Problem statement: Consider a row of n coins of values v1 . . . vn, where n is even. We play a game against an opponent by alternating turns. In each turn, a player selects either the first or last coin from the row, removes it from the row permanently, and receives the value of the coin. Determine the maximum possible amount of money we can definitely win if we move first.
*/

#include <iostream>
#include <vector>
using namespace std;


int OptimalGame(const vector<int> &a)
{
	int N = a.size();
	vector<vector<int>> table(N);
	for(auto &v: table)
		v.resize(N, 0);	
	for(int gap = 1; gap < N; gap+=2)
	{
		for(int i = 0; i+gap < N; i++)
		{
			int lo = i;
			int hi = lo+gap;
			if(hi-lo == 1)
			{
				table[lo][hi] = max(a[lo], a[hi]);
				continue;
			}
			table[lo][hi] = max(a[lo]+min(table[lo+1][hi-1], table[lo+2][hi]),
					    a[hi]+min(table[lo+1][hi-1], table[lo][hi-2]));
		}
	}
	return table[0][N-1];
}

int main()
{
        vector<int>a1 = {8, 15, 3, 7};
        vector<int>a2= {2, 2, 2, 2};
        vector<int>a3= {20, 30, 2, 2, 2, 10};
        cout<<OptimalGame(a1)<<endl;
        cout<<OptimalGame(a2)<<endl;
        cout<<OptimalGame(a3)<<endl;
	return 0;
}
