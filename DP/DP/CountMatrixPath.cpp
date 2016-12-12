/*
Count all possible paths from top left to bottom right of a mXn matrix
The problem is to count all the possible paths from top left to bottom right of a mXn matrix with the constraints that from each cell you can either move only to right or down
*/

#include <iostream>
#include <vector>
using namespace std;

int CountMatrixPath(int M, int N)
{
	vector<vector<int>> table(M);
	for(auto &v: table)
		v.resize(N, 1);
	for(int i = 1; i < M; i++)
	{
		for(int j = 1; j < N; j++)
			table[i][j] = table[i-1][j]+table[i][j-1];

	}
	return table[M-1][N-1];
}
int main()
{
        int M = 5;
        int N = 6;
        cout<<CountMatrixPath(M, N)<<endl;
        return 0;
}

