/*
Given a boolean matrix mat[M][N] of size M X N, modify it such that if a matrix cell mat[i][j] is 1 (or true) then make all the cells of ith row and jth column as 1. 
*/

#include <iostream>
#include <vector>
using namespace std;


void print(const vector<vector<int>> &a)
{
	int N = a.size();
	if(N==0)
		return;
	int M = a[0].size();
	for(const auto &v: a)
	{
		for(const int &x:v)
			cout<<x<<" ";
		cout<<endl;
	}
	cout<<endl;
}

void Convert(vector<vector<int>> &a)
{
	int N = a.size();
	if(N==0)
		return;
	int M = a[0].size();
	bool r = false;
	bool c = false;
	for(int i = 0; i < N; i++)
	{
		if(a[i][0] == 1)
		{
			c = true;
			break;
		}
	}
	for(int j = 0; j < M; j++)
	{
		if(a[0][j] == 1)
		{
			r = true;
			break;
		}
	}
	for(int i = 1; i < N; i++)	
	{
		for(int j = 1; j < M; j++)
		{
			if(a[i][j] == 1)
			{
				a[0][j] = 1;
				a[i][0] = 1;
			}
		}
	}
	for(int i = 1; i < N; i++)
	{
		if(a[i][0] == 1)
		{
			for(int j = 1; j < M; j++)
				a[i][j] = 1;
		}
	}
	for(int j = 1; j < M; j++)
	{
		if(a[0][j] == 1)
		{
			for(int i = 1; i < N; i++)
				a[i][j] = 1;
		}
	}
	if(r)
	{
		for(int j = 1; j < M; j++)
			a[0][j] = 1;
	}
	
	if(c)
	{
		for(int i = 1; i < N; i++)
			a[i][0] = 1;
	}
}

int main()
{
	vector<vector<int>> a =
			 { {1, 0, 0, 1},
               {0, 0, 1, 0},
               {0, 0, 0, 0}
             };
	print(a);
	Convert(a);
	print(a);
	return 0;
}
