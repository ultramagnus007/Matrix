/*
Count all possible paths from top left to bottom right of a mXn matrix
The problem is to count all the possible paths from top left to bottom right of a mXn matrix with the constraints that from each cell you can either move only to right or down
*/

#include <iostream>
using namespace std;

bool isValid(int i, int j, int M, int N)
{
	return i>=0 && j>=0 && i<M && j<N;
}

int CountPaths(int i, int j, int M, int N)
{
	if(!isValid(i, j, M, N))
		return 0;
	if(i==M-1 && j == N-1)
		return 1;
	return CountPaths(i+1, j, M, N)+CountPaths(i, j+1, M, N);
}

int main()
{
        int M = 5;
        int N = 6;


	cout<<CountPaths(0, 0, M, N)<<endl;

	return 0;
}
