/*
Find k closest elements to a given value

Given a sorted array arr[] and a value X, find the k closest elements to X in arr[].
Examples:

Input: K = 4, X = 35
       arr[] = {12, 16, 22, 30, 35, 39, 42, 
               45, 48, 50, 53, 55, 56}
Output: 30 39 42 45

Note that if the element is present in array, then it should not be in output, only the other closest elements are required.
*/

#include <iostream>
#include <vector>
using namespace std;


void PrintKClosest(const vector<int> & a, int X, int K)
{
	if(a.size() == 0)
		return;
	int N = a.size();
	int lo = 0, hi = N-1;
	int mid = lo;
	while(lo < hi)
	{
		mid = (lo+hi)/2;
		if(a[mid] == X)	
			break;
		else if(a[mid] < X)
			lo = mid+1;
		else
			hi = mid-1;
	}
	int i = mid-1;
	int j = mid+1;
	if(a[mid] != X)
	{
		K--;
		cout<<a[mid]<<" ";
	}
	while(K>0 && i >=0 && j < N)
	{
		if(X- a[i] <= a[j]-X )
			cout<<a[i--]<<" ";
		else
			cout<<a[j++]<<" ";
		K--;
	}
	while(K > 0 && i >=0)
	{
		cout<<a[i--]<<" ";
		K--;
	}
	while(K > 0 &&  j < N)
	{
		cout<<a[j++]<<" ";
		K--;
	}
	cout<<endl;
}
int main()
{
	vector<int> a = {12, 16, 22, 30, 35, 39, 42, 45, 48, 50, 53, 55, 56};
	int X = 35;
	int K = 4;
	PrintKClosest(a, X, K);
	return 0;
}
