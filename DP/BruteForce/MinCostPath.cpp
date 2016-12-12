/*
Given a cost matrix cost[][] and a position (m, n) in cost[][], write a function that returns cost of minimum cost path to reach (m, n) from (0, 0). Each cell of the matrix represents a cost to traverse through that cell. Total cost of a path to reach (m, n) is sum of all the costs on that path (including both source and destination). You can only traverse down, right and diagonally lower cells from a given cell, i.e., from a given cell (i, j), cells (i+1, j), (i, j+1) and (i+1, j+1) can be traversed. You may assume that all costs are positive integers.
*/
#include <iostream>
#include <climits>
using namespace std;

const int R = 3;
const int C = 3;
int a[R][C] = { {1, 2, 3},
                {4, 8, 2},
                {1, 5, 3}
              };


bool isValid(int i, int j)
{
	return i>=0 && j>=0 && i<R && j<C;
}


int MinCost(int i, int j)
{
	if(!isValid(i, j))
		return 1000000;
	if(i == R-1 && j == C-1)
		return a[i][j];
	return a[i][j]+min(MinCost(i+1, j+1), min(MinCost(i+1, j), MinCost(i, j+1)));
}

int main()
{
	cout<<MinCost(0, 0)<<endl;
	return 0;
}
