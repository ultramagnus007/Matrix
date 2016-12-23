#include <iostream>
#include "Sort.h"
using namespace std;


void partition(vector<int> &a, int lo, int hi, int &p1, int &p2)
{
	int pivot = a[hi];
	int k = lo;
	p1 = lo;
	p2 = hi;
	while(true)
	{
		if(a[k] < a[pivot])
			swap(a[k++], a[p1++]);
		else if(a[k] > pivot)
			swap(a[k], a[p2--]);
		else
			k++;
	}	
}

void QuickSort3Way(vector<int> &a, int lo,  int hi)
{
	if(lo >= hi)
		return;
	int p1, p2;
	partition(a, lo, hi, p1, p2);
	QuickSort3Way(a, p2+1, hi);
	QuickSort3Way(a, lo, p1-1);
}

void QuickSort3Way(vector<int> &a)
{
	QuickSort3Way(a, 0, a.size()-1);
}

