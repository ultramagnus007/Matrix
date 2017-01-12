//For Range minimum query
#include <iostream>
#include <climits>
#include <cstdlib>
#include <ctime>
#include <vector>
using namespace std;

inline int parent(int i)
{
	return (i-1)/2;
}
inline int left(int i)
{
	return 2*i+1;
}
inline int right(int i)
{
	return 2*i+2;
}
int minRange(const vector<int> &a, int i, int j)
{
	int ans = INT_MAX;
	for(int k = i; k<= j; k++)
		ans = min(ans, a[k]);
	return ans;
}

void ContructTree(vector<int> &SG)
{
	int N = (SG.size()+1)/2;
	for(int i = N-2; i >= 0; i--)
		SG[i] = min(SG[left(i)], SG[right(i)]);
}


int RangeMinQ(const vector<int> &SG, int i, int l, int r,  int lo, int hi)
{
	if(l > r)
		return INT_MAX;
	if(lo <= l && r <= hi)
		return SG[i];
	if(hi < l || lo > r)
		return INT_MAX;
	if(l==r)
		return INT_MAX;
	int mid = (l+r)/2;
	return min(RangeMinQ(SG, left(i), l, mid, lo, hi)	, RangeMinQ(SG, right(i), mid+1, r, lo, hi));
}

int main()
{
	int N  = 100;
	vector<int> a(N);
	srand(time(NULL));
	for(auto &x: a)
		x = rand()%100;
	//if N is power of 2 then total number of nodes in array = N leaf + N-1 internal node
	int n = 1;
	while(n < N)
		n = 2*n;
	int size = 2*n-1;
	vector<int > SG(size, INT_MAX);
	for(int i = n-1, j = 0; j < N; i++, j++)
		SG[i] = a[j];
	ContructTree(SG);
	for(int i = 0; i < a.size(); i++)
	{
		for(int j = i; j < a.size(); j++)
		{
			int m1 = minRange(a, i, j);
			int m2 = RangeMinQ(SG, 0, n-1, 2*n-2, n-1+i, n-1+j);
			if(m1 != m2)		
			{
				cout<<"BAD: "<<i<<" "<<j<<endl;
				return 0;
			}
		}
	}
	cout<<"GOOD"<<endl;
	return 0;	
}
