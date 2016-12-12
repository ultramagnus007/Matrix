/*
Create a matrix with alternating rectangles of O and X
Write a code which inputs two numbers m and n and creates a matrix of size m x n (m rows and n columns) in which every elements is either X or 0. The Xs and 0s must be filled alternatively, the matrix should have outermost rectangle of Xs, then a rectangle of 0s, then a rectangle of Xs, and so on.

*/

#include <iostream>
#include <vector>
using namespace std;


void fillMatrix(vector<vector<char>> &a)
{
	if(a.size()==0)
		return;
	int M = a.size();
	int N = a[0].size();
	int top = 0, bottom = M-1, left = 0, right = N-1;
	
	bool isX = true;
	while(top<=bottom && left<=right)
	{
		if(top==bottom)
		{
			for(int i = left; i<=right; i++)
				a[top][i] = isX?'X':'O';
		}
		else if(left==right)
		{
			for(int i = top; i<= bottom; i++)
				a[i][left] = isX?'X':'O';
		}else
		{
			for(int i = left; i<= right; i++)
				a[top][i] = isX?'X':'O';
			for(int i = top+1; i<=bottom; i++)
				a[i][right] = isX?'X':'O';
			for(int i = right-1; i>=left; i--)
				a[bottom][i] = isX?'X':'O';
			for(int i = bottom-1; i> top; i--)
				a[i][left] = isX?'X':'O';
		}
		top++,bottom--,left++,right--;
		isX=!isX;
	}
}


int main()
{
    cout<<"Enter dimension m and n of Matrix\n";
    int M, N;
    cin>>M>>N;
	vector<vector<char>> a(M);
	for(auto &v:a)
		v.resize(N, ' ');
	fillMatrix(a);
	for(int i = 0; i < M; i++)
	{
		for(int j = 0; j < N; j++)
			cout<<a[i][j]<<" ";
		cout<<endl;
	}
	return 0;
}
