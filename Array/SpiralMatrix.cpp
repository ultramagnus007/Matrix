#include <iostream>
#include <vector>
using namespace std;

void print(vector<vector<int>> &a)
{
	if(a.size()==0)
		return;
	int M = a.size();
	int N = a[0].size();
	for(int i = 0; i < M; i++)
	{
		for(int j = 0; j < N; j++)
		{
			cout<<a[i][j]<<" ";
			if(a[i][j] < 10)
			cout<<" ";
		}
		cout<<endl;
	}
}

void spiralprint(vector<vector<int>> &a)
{
	if(a.size()==0)
		return;
	int M = a.size();
	int N = a[0].size();
	int top = 0, bottom = M-1, left = 0, right = N-1;
	while(top<=bottom && left <= right)
	{
		if(top==bottom)
		{
			for(int i = left; i <= right; i++)
				cout<<a[top][i]<<" ";
			cout<<endl;
			break;
		}else if(left == right)
		{
			for(int i = top; i <= bottom; i++)
				cout<<a[i][left]<<" ";
			cout<<endl;
			break;
		}
		for(int i = left; i <= right; i++)
			cout<<a[top][i]<<" ";
		for(int i = top+1; i<= bottom; i++)
			cout<<a[i][right]<<" ";
		for(int i = right-1; i>=left; i--)
			cout<<a[bottom][i]<<" ";
		for(int i = bottom-1; i > top; i--)
			cout<<a[i][left]<<" ";
		cout<<endl;
		top++,bottom--,left++,right--;
	}
}

int main()
{
	const int M = 7;
	const int N = 5;
	vector<vector<int>> a(M);
	int val = 1;
	for(auto &v:a)
	{
		v.resize(N);
		for(auto &x:v)
			x = val++;
	}
	print(a);
	spiralprint(a);
	return 0;
}
