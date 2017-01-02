/*
The objective is to fill a 9×9 grid with digits so that each column, each row, and each of the nine 3×3 sub-grids that compose the grid (also called "boxes", "blocks", "regions", or "sub-squares") contains all of the digits from 1 to 9.
*/
#include <iostream>
#include <vector>
using namespace std;
bool isvalid(const vector<vector<int>> &a, int i, int j, int x)
{
	int sx = (i/3)*3;
	int sy = (j/3)*3;
	for(int p = sx; p <= sx+2; p++)
	{
		for(int q = sy; q < j; q++)
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
void print(const vector<vector<int>> &a)
{
	for(const auto &v: a)
	{
		for(const auto &x: v)
			cout<<x<<" ";
		cout<<endl;
	}
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
	for(int x = 1; x <= 9; x++)
	{
		if(!isvalid(a, i, j, x))
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
	const int N = 9;
	vector<vector<int>> a(N);
	for(auto &v:a)
		v.resize(N, 0);
	Sudoku(a, 0, 0);
	print(a);
	return 0;
}
