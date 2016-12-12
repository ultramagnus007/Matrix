/*
Print all possible paths from top left to bottom right of a mXn matrix

The problem is to print all the possible paths from top left to bottom right of a mXn matrix with the constraints that from each cell you can either move only to right or down.
*/

#include <iostream>
#include <vector>
using namespace std;


bool isValid(int i, int j, int M, int N)
{
	return i>=0 && j>=0 && i<=M && j<=N;
}

void print(const vector<int> &paths)
{
	for(const auto &p: paths)
		cout<<p<<" ";
	cout<<endl;
}

void findPaths(int i,  int j, int M, int N, vector<int> &paths)
{
	if(!isValid(i, j, M, N))
		return;
	paths[i+j] = i*N+j+1;
	if(i==M-1 && j==N-1)
	{
		print(paths);
		return;	
	}
	findPaths(i+1, j, M, N, paths);
	findPaths(i, j+1, M, N, paths);

}

int main()
{
	const int M = 2, N =3;
	vector<int> paths(M+N-1);
	findPaths(0, 0, M, N, paths);
	return 0;
}


#if 0
bool isValid(int i, int j, int M, int N)
{
	return i>=0 && j>=0 && i<=M && j<=N;
}


void print(const vector<pair<int,int>> &paths)
{
	for(const auto &p: paths)
		cout<<"("<<p.first<<","<<p.second<<") ";
	cout<<endl;
}

void findPaths(int i,  int j, int M, int N, vector<pair<int,int>> &paths)
{
	if(!isValid(i, j, M, N))
		return;
	paths[i+j].first = i;
	paths[i+j].second = j;

	if(i==M && j==N)
	{
		print(paths);
		return;	
	}
	findPaths(i+1, j, M, N, paths);
	findPaths(i, j+1, M, N, paths);
}
int main()
{
	const int M = 2, N =3;
	vector<pair<int, int>> paths(M+N+1);
	findPaths(0, 0, M, N, paths);
	return 0;
}
#endif
