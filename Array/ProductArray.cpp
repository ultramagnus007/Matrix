/*
Get an array B such that B[i] has the product of all numbers of A except A[i]
without using division operator in O(n) time
*/

#include <iostream>
#include <vector>
using namespace std;




int main()
{
	int N = 5;
	vector<int> a(N);
	for(int i = 0; i < N; i++)
		a[i] = i+1;
	vector<int> B(N, 1);
	int left = 1;
	int right = 1;
	for(int i = 0; i < N; i++)
	{
		B[i] *= left;
		B[N-i-1] *= right;
		left *= a[i];
		right *= a[N-i-1];
	}

	#if 0
	// it is two pass
	for(int i = 0; i < N; i++)
	{
		B[i] *= left;
		left *= a[i];
	}
	for(int i = N-1; i >= 0; i--)
	{
		B[i] *= right;
		right *= a[i];
	}
	#endif
	for(auto &x: B)
		cout<<x<<" ";
	cout<<endl;
}
