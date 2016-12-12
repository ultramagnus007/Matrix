#include <iostream>
#include <vector>
using namespace std;

void print(vector<vector<int>> &a)
{
	for(auto &v:a)
	{
		for(auto &x:v)
		{
			cout<<x<<" ";
			if(x < 10)
				cout<<" ";
		}
		cout<<endl;
	}
}

void Rotate90(vector<vector<int>> &a)
{
	int N = a.size();
	int lo = 0, hi = N-1;
	while(lo < hi)
	{
		for(int i = lo; i < hi; i++)
		{
			swap(a[lo][i], a[lo+i-lo][hi]);
			swap(a[lo][i], a[hi][hi-i+lo]);
			swap(a[lo][i], a[hi-i+lo][lo]);
		}
		lo++;
		hi--;
	}	
}

int main()
{
	int N;
	cout<<"Enter the N"<<endl;
	cin>>N;
	vector<vector<int>> a(N);
	int val = 0;
	for(auto &v:a)
	{
		v.resize(N);
		for(auto &x:v)
			x = ++val;
	}
	print(a);
	Rotate90(a);
	cout<<endl;
	print(a);
	return 0;
}
