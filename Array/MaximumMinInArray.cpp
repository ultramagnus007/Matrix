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
	int mid = (lo+hi)/2;
	DivideAndConquer(a, lo, mid-1, Min, Max);
	DivideAndConquer(a, mid+1, hi, Min, Max);
	dccount+=2;
	if(a[mid] < Min)
	{
		Min = a[mid];
		dccount--;
	}
	else if(a[mid] > Max)
	{
		Max = a[mid];
	}
}
int main()
{
	int N = 100;
	srand(time(NULL));
    vector<int> a(N);
	for(auto &x: a)
		x = rand()%N;
	iterativeFind(a);
	int Min = INT_MAX;
	int Max = INT_MIN;
	DivideAndConquer(a, 0, a.size()-1, Min, Max);
	cout<<Min<<" "<<Max<<endl;
	cout<<itcount<<" "<<dccount<<endl;
	return 0;
}
