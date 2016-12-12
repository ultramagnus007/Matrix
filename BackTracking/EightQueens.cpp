#include <iostream>
#include <vector>
using namespace std;



const int N = 8;

bool issafe(vector<vector<bool>> & a, int p, int q)
{

	for(int j = q-1; j >= 0; j--)
		if(a[p][j]) return false;
	for(int i = p-1, j = q-1; i>=0 && j>=0; i--,j--)
		if(a[i][j]) return false;
	for(int i = p+1, j = q-1; i< N && j >=0; i++, j--)
		if(a[i][j]) return false;
	return true;
}		



bool Solve(vector<vector<bool>> & a, int j)
{
	if( j == 8)
		return true;
	for(int i = 0; i < N; i++)
	{
		if(issafe(a, i, j) == false)
			continue;
		a[i][j] = true;
		if(Solve(a, j+1))
			return true;
		a[i][j] = false;
	}
	return false;
}

void print(vector<vector<bool>> &a)
{
	for(int i = 0; i < N; i++)
	{
		for(int j = 0; j < N; j++)
		{
			if(a[i][j])
			cout<<'O'<<" ";
			else
			cout<<'X'<<" ";
		}
		cout<<endl;
	}
}
int main()
{
	vector<vector<bool>> board(N);
	for(auto &v: board)
		v.resize(N, false);
	Solve(board, 0);
	print(board);
	return 0;
}
