#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <algorithm>
using namespace std;

int partition(vector<int> &a, int &p, int &q)
{
	int pivot = a[q];
	int i = p;
	while(i<=q)
	{
		if(a[i] > pivot)
			swap(a[i], a[q--]);
		else if(a[i] < pivot)
			swap(a[i++], a[p++]);
		else
			i++;
	}
}
int KthLargest(vector<int> &a, int lo, int hi, int K)
{
	int p =lo, q = hi;
	partition(a, p, q);
	if(p <= lo+K-1 && lo+K-1 <= q)
		return a[p];
	else if(p > lo+K-1)
		return KthLargest(a, lo, p-1, K);
	else
		return KthLargest(a, q+1, hi, K-q+lo-1);
}

int main()
{
	const int N = 100000;
	int K = 0.65*N;
	vector<int> a(N);
	srand(time(NULL));
	for(auto &x	: a)
		x = rand();
	cout<<KthLargest(a, 0, a.size()-1, K)<<endl;
	sort(a.begin(), a.end());
	cout<<a[K-1]<<endl;
	return 0;
}
