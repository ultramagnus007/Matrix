/*
Given a cost matrix cost[][] and a position (m, n) in cost[][], write a function that returns cost of minimum cost path to reach (m, n) from (0, 0). Each cell of the matrix represents a cost to traverse through that cell. Total cost of a path to reach (m, n) is sum of all the costs on that path (including both source and destination). You can only traverse down, right and diagonally lower cells from a given cell, i.e., from a given cell (i, j), cells (i+1, j), (i, j+1) and (i+1, j+1) can be traversed. You may assume that all costs are positive integers.
*/
#include <iostream>
#include <vector>
#include <climits>
using namespace std;

const int R = 3;
const int C = 3;
int a[R][C] = { {1, 2, 3},
                {4, 8, 2},
                {1, 5, 3}
              };

int MinCostPath()
{
	vector<vector<int>> table(R);
	for(auto &v:table)
		v.resize(C, 0);
	table[0][0] = a[0][0];
	for(int i = 1; i < R; i++)
		table[i][0] = a[i][0] + table[i-1][0];
	for(int j = 1; j < C; j++)
		table[0][j] = a[0][j] + table[0][j-1];
	for(int i = 1; i < R; i++)
	{
		for(int j = 1; j < C; j++)
		{
			table[i][j] = a[i][j]+min(table[i-1][j-1], min(table[i-1][j], table[i][j-1]));
		}
	}
	return table[R-1][C-1];
}

int main()
{
        cout<<MinCostPath()<<endl;
	return 0;
}
