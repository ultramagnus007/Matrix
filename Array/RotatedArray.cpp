/*
A sorted array is rotated at some unknown point, find the minimum element in it.

Following solution assumes that all elements are distinct.

Examples

Input: {5, 6, 1, 2, 3, 4}
Output: 1

Input: {1, 2, 3, 4}
Output: 1

Input: {2, 1}
Output: 1
*/

#include <iostream>
#include <vector>
using namespace std;


int findMin(const vector<int> &a)
{
	int N = a.size();
	int lo = 0;
	int hi = N-1;
	while(lo <= hi)
	{
		int mid = (lo+hi)/2;
		if((mid-1 < 0 || a[mid-1] > a[mid]) && 
				(mid+1>N-1 || a[mid+1] >  a[mid]) )
			return a[mid];
		if(a[hi] > a[mid])
			hi = mid;
		else
			lo = mid+1;
	}	
	return -1;
}


int main()
{
    const int N =10;
    vector<vector<int>> a(N);
	for(int i = 0; i < N; i++)
	{
		a[i].resize(N);
		for(int j = 0; j < N; j++)
			a[i][j] = (i+j)%(N)+1;
	}
	for(auto &v:a)
	{
		for(auto &x: v)
			cout<<x<<" ";
		cout<<endl;
	}
    for(int i = 0; i < N; i++)
	    cout<<"minimum element is "<<findMin(a[i])<<endl;
    return 0;
}

