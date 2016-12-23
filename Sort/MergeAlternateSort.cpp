#include "Sort.h"
#include <vector>
using namespace std;


void Merge(vector<int> &a, vector<int> &b, int lo, int hi)
{
	int mid = (lo+hi)/2;
	int i = lo;
	int j = mid+1;
	int k = lo;
	while(i<=mid && j<=hi)
	{
		if(a[i] < a[j])
			b[k++] = a[i++];
		else if(a[i] > a[j])
			b[k++] = a[j++];
		else
		{
			b[k++] = a[i++];
			b[k++] = a[j++];
		}
	}
	while(i<=mid)
		b[k++] = a[i++];
	while(j<=hi)
		b[k++] = a[j++];
}

void MergeSort(vector<int> &a, vector<int> &b, int lo, int hi)
{
	if(lo>=hi)
		return;
	int mid = (lo+hi)/2;
	MergeSort(b, a, lo, mid);
	MergeSort(b, a, mid+1, hi);
	Merge(b, a, lo, hi);
}

void MergeAlternateSort(vector<int> &a)
{
	int N = a.size();
	vector<int> b(N);
	for(int i = 0; i < N; i++)
		b[i] = a[i];
	MergeSort(a, b, 0, N-1);
}
