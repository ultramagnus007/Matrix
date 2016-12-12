#include <iostream>
#include <vector>
using namespace std;

const int N = 8;

bool isValid(int i, int j)
{
	return i>=0 && j>=0 && i<N && j<N;
}

bool KnightTour(vector<vector<int>> &a, int i, int j, int &count)
{
	if(count == N*N)
		return true;
	int CO[8][2] = {{i+2, j+1},{i+1, j+2},{i-1, j+2},{i-2, j+1},
				{i-2, j-1},{i-1, j-2},{i+1, j-2},{i+2, j-1}};
	for(int k = 0; k < 8; k++)
	{
		int x = CO[k][0];
		int y = CO[k][1];
		if(!isValid(x,y) || a[x][y] != 0)
			continue;
		a[x][y] = ++count;
		if(KnightTour(a, x, y, count))
			return true;
		a[x][y] = 0;
		--count;
	}
	return false;
}

void print(vector<vector<int>> &a)
{
	for(int i = 0 ; i < a.size(); i++)
	{
		for(int j = 0 ; j < a[i].size(); j++)
		{
			cout<<a[i][j]<<" ";
			if(a[i][j] < 10)
			cout<<" ";
		}
		cout<<endl;
	}
}
int main()
{
	vector<vector<int>> a(N);
	for(auto&v : a)
		v.resize(N, 0);
	int count = 0;
	a[0][0] = ++count;	
	KnightTour(a, 0, 0, count);
	print(a);
	return 0;
}
