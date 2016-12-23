/*
Maximum and minimum of an array using minimum number of comparisons
*/



#include <iostream>
#include <vector>
#include <climits>
#include <cstdlib>
#include <ctime>
using namespace std;

int itcount = 0;
int dccount = 0;
int cpcount = 0;
void iterativeFind(const vector<int> &a)
{
	int Min = INT_MAX;
	int Max = INT_MIN;
	for(const auto &x: a)
	{
		itcount+=2;
		if(x < Min)
		{
			Min = x;	
			itcount--;
		}
		else if(x > Max)
		{
			Max = x;
		}
	}
	cout<<Min<<" "<<Max<<endl;
}

void DivideAndConquer(const vector<int> &a, int lo, int hi, int &Min, int &Max)
{
	if(lo > hi)
		return;
	if(hi-lo == 1)
	{
		dccount++;
		if(a[hi] > a[lo])
		{
			Min = a[lo];
			Max = a[hi];
		}else
		{
			Min = a[hi];
			Max = a[lo];
		}
		return;
	}
	if(lo==hi)
	{
		Min = a[lo];
		Max = a[hi];
		return;
	}
	int mid = (lo+hi)/2;
	int minL = INT_MAX, minR = INT_MAX;
	int maxL = INT_MIN, maxR = INT_MIN;
	DivideAndConquer(a, lo, mid, minL, maxL);
	DivideAndConquer(a, mid+1, hi, minR, maxR);
	dccount+=2;
	Min = min(minL, minR);
	Max = max(maxL, maxR);
}

void ComparePairs(const vector<int> &a)
{
	int N = a.size();
	pair<int, int> minmax(INT_MAX, INT_MIN);
	int i = 0;
	for(int i = 0; i+1<N;i+=2)
	{
		cpcount+=3;
		pair<int, int> localminmax;
		if(a[i] > a[i+1])	
		{
			localminmax.first = a[i+1];
			localminmax.second = a[i];
		}else
		{
			localminmax.first = a[i];
			localminmax.second = a[i+1];
		}
		if(localminmax.first < minmax.first)
				minmax.first = localminmax.first;
		if(localminmax.second > minmax.second)
				minmax.second = localminmax.second;
	}
	if(i==N-1)
	{
		cpcount++;
		if(a[i] < minmax.first)
			minmax.first = a[i];
		else if(a[i] > minmax.second)
			minmax.second = a[i];
	}
	cout<<minmax.first<<" "<<minmax.second<<endl;
}

int main()
{
	int N = 100000;
	srand(time(NULL));
    vector<int> a(N);
	for(auto &x: a)
		x = rand()%N;
	iterativeFind(a);
	int Min = INT_MAX;
	int Max = INT_MIN;
	DivideAndConquer(a, 0, a.size()-1, Min, Max);
	cout<<Min<<" "<<Max<<endl;
	ComparePairs(a);
	cout<<itcount<<" "<<dccount<<" "<<cpcount<<endl;
	return 0;
}
