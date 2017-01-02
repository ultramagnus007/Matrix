#include "Sort.h"
#include <vector>
using namespace std;

inline int getbyte(int x, int d)
{
	return 0xff&(x>>(8*d));
}

void RadixSort(vector<int> &a, int lo, int hi, int d)
{
	if(lo >=hi)
		return;
	const int R = 256;
	vector<int> b(hi-lo+1);
	vector<int> count(R, 0);
	vector<int> C(R, 0);
	for(int i = lo; i <= hi; i++)
		count[getbyte(a[i], d)]++;
	for(int i = 1; i < R; i++)
		count[i]+=count[i-1];
	for(int i = 0; i < R; i++)
		C[i] = count[i];

	for(int i = hi; i >= lo; i--)
		b[count[getbyte(a[i], d)]-- -1] = a[i];

	for(int i = lo; i <= hi; i++)
		a[i] = b[i];
	if(d > 0)
	{
		int last = 0;
		for(int i = 0; i < R; i++)
		{
			RadixSort(a, last, C[i]-1, d-1);
			last = C[i]-1;
		}
	}
}

void RadixSortMSD(vector<int> &a)
{
    RadixSort(a, 0, a.size()-1, 3);
}

