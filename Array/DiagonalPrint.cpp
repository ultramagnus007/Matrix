#include <iostream>
#include <vector>
using namespace std;


void DiagonalPrint(vector<vector<int>> &a)
{
	if(a.size()==0)
		return;
	int M = a.size();
	int N = a[0].size();
	for(int k = 0; k < M; k++)
	{
		for(int i = k, j = 0; i>=0 && j< N; i--,j++)
			cout<<a[i][j]<<" ";
		cout<<endl;
	}
	for(int k = 1; k < N; k++)
	{
		for(int i = M-1, j=k; i>=0 && j < N; i--, j++)
			cout<<a[i][j]<<" ";
		cout<<endl;
	}
}

int main()
{
	int M, N;
	cout<<"Enter M and N"<<endl;
	cin>>M>>N;
	vector<vector<int>> a(M);
	
	int val = 1;
	for(auto &v: a)
	{
		v.resize(N);
		for(auto &x:v)
			x = val++;
	}
	DiagonalPrint(a);
	return 0;
}
