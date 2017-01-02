#include <iostream>
#include "Sort.h"
using namespace std;

void partition(vector<int> &a, int &p, int &q)
{
	int pivot = a[(p+q)/2];
	int i = p;
	while(i <= q)
	{
		if(a[i] > pivot)
			swap(a[q--], a[i]);
		else if(a[i] < pivot)
			swap(a[p++], a[i++]);
		else
			i++;
	}
}
void QuickSort3Way(vector<int> &a, int lo,  int hi)
{
	if(lo >= hi)
		return;
	int p1 = lo, p2 = hi;
	partition(a, p1, p2);
	QuickSort3Way(a, lo, p1-1);
	QuickSort3Way(a, p2+1, hi);
}


void QuickSort3Way(vector<int> &a)
{
	QuickSort3Way(a, 0, a.size()-1);
}

