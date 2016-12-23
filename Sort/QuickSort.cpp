#include "Sort.h"
#include <vector>
using namespace std;


int partition(vector<int> &a, int lo, int hi)
{
	int pivot = hi;
	int i = lo, j = hi;
	while(i < j)
	{
		while(i<=j && a[i] < a[pivot])
				i++;
		while(i<=j && a[j] >= a[pivot])
				j--;
		if(i < j)
			swap(a[i], a[j]);
	}
	swap(a[pivot], a[i]);
	return i;
}

void QuickSort(vector<int> &a, int lo, int hi)
{
	if(lo >= hi)
		return;
	int pivot = partition(a, lo, hi);
	QuickSort(a, lo, pivot-1);
	QuickSort(a, pivot+1, hi);
}

void QuickSort(vector<int> &a)
{
	QuickSort(a, 0, a.size()-1);
}
