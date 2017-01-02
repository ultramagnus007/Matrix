/*
A Maze is given as N*N binary matrix of blocks where source block is the upper left most block i.e., maze[0][0]
and destination block is lower rightmost block i.e., maze[N-1][N-1]. 
A rat starts from source and has to reach destination. 
The rat can move only in two directions: forward and down.
*/
#include <iostream>
#include <vector>
using namespace std;

bool isValid(int i, int j, int N)
{
	return i>=0 && j>=0 && i<N && j<N;
}
void print(const vector<vector<int>> &a)
{
	for(const auto& v: a)
	{
		for(auto x: v)
			cout<<x<<" ";
		cout<<endl;
	}
}
bool RatInMaze(const vector<vector<int>> &maze, vector<vector<int>> & a, int i, int j)
{
	int N = maze.size();
	if(!isValid(i, j, N) || maze[i][j] == 0)
		return false;
	a[i][j] = 1;
	if(i == N-1 && j == N-1)
		return true;
	return RatInMaze(maze, a, i+1, j) || RatInMaze(maze, a, i, j+1);
}
int main()
{
const int N = 4;
vector<vector<int>> maze { {1, 0, 0, 0},
						   {1, 1, 0, 1},
		                   {0, 1, 0, 0},
					       {1, 1, 1, 1}
						 };
	vector<vector<int>> a(N);
	for(auto &v: a)
		v.resize(N, 0);
	RatInMaze(maze, a, 0, 0);
	print(a);
	return 0;
}
