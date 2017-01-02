#include "Sort.h"

inline unsigned int getbyte(int x, int d)
{
	return 0xff&(x>>(d*8));
}

void RadixSortLSD(vector<int> &a)
{
	const int R = 256;
	vector<int> b(a.size());
	for(int d = 0; d < 4; d++)
	{
		vector<int> count(R, 0);
		for(const auto &x: a)
			count[getbyte(x,d)]++;
		for(int i = 1; i < R; i++)
			count[i]+=count[i-1];
		for(int i = a.size()-1; i >= 0; i--)
			b[count[getbyte(a[i], d)]-- -1] = a[i];
		for(int i = 0; i < b.size(); i++)
			a[i] = b[i];
	}
}
