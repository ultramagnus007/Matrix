/*
Given a partially filled 9×9 2D array ‘grid[9][9]‘, the goal is to assign digits (from 1 to 9)
to the empty cells so that every row, column, and subgrid of size 3×3 contains exactly one instance
of the digits from 1 to 9. 
*/
#include <iostream>
#include <vector>
using namespace std;

void print(const vector<vector<int>> &a)
{
	for(const auto &v: a)
	{
		for(const auto &x: v)
			cout<<x<<" ";
		cout<<endl;
	}
}

bool isValid(const vector<vector<int>> &a, int i, int j, int x)
{
	int sx = (i/3)*3;
	int sy = (j/3)*3;
	for(int p = sx; p <= sx+2; p++)
	{
		for(int q = sy; q <= sy+2; q++)
		{
			if(a[p][q] == x)
				return false;
		}
	}
	for(int p = 0; p < i; p++)
		if(a[p][j] == x) return false;

	for(int q = 0; q < j; q++)
		if(a[i][q] == x) return false;
	return true;
}
bool Sudoku(vector<vector<int>> &a, int i, int j)
{
	if(i == a.size())
	{
		j++;
		i = 0;
	}
	if(j == a.size())
		return true;
	if(a[i][j] != 0)
		return Sudoku(a, i+1, j);
	for(int x=1; x<=9; x++)
	{
		if(!isValid(a, i, j, x))
			continue;
		a[i][j] = x;
		if(Sudoku(a, i+1, j))
			return true;
		a[i][j] = 0;
	}
	return false;
}

int main()
{
vector<vector<int>>a{{3, 0, 6, 5, 0, 8, 4, 0, 0},
	               {5, 2, 0, 0, 0, 0, 0, 0, 0},
		           {0, 8, 7, 0, 0, 0, 0, 3, 1},
			       {0, 0, 3, 0, 1, 0, 0, 8, 0},
				   {9, 0, 0, 8, 6, 3, 0, 0, 5},
	               {0, 5, 0, 0, 9, 0, 6, 0, 0},
		           {1, 3, 0, 0, 0, 0, 2, 5, 0},
			       {0, 0, 0, 0, 0, 0, 0, 7, 4},
				   {0, 0, 5, 2, 0, 6, 3, 0, 0}};

	print(a);
	Sudoku(a, 0, 0);
	cout<<"---------------------------------"<<endl;
	print(a);
	return 0;
}
