/*
Smallest subarray with sum greater than a given value

Given an array of integers and a number x, find the smallest subarray with sum greater than the given value.

Examples:
arr[] = {1, 4, 45, 6, 0, 19}
   x  =  51
Output: 3
Minimum length subarray is {4, 45, 6}

arr[] = {1, 10, 5, 2, 7}
   x  = 9
Output: 1
Minimum length subarray is {10}

arr[] = {1, 11, 100, 1, 0, 200, 3, 2, 1, 250}
    x = 280
Output: 4
Minimum length subarray is {100, 1, 0, 200}
*/

#include <iostream>
#include <vector>
using namespace std;

int SmallestSubarray(vector<int> &a, int X)
{
	int N = a.size();
	if(N==0)
		return -1;
	int i = 0, j = 0;
	int si = 0, ei = N;
	int S = 0;
	while(i< N && j < N)
	{
		if(S <= X)
			S+=a[j++];
		if(S > X)
		{
			if(ei-si > j-i)
			{
				si = i;
				ei = j;
			}
			S-=a[i++];
		}
	}
	if(ei-si == N)
		return -1;
	return ei-si;
}

int main()
{
	vector<int> a1 = {1, 4, 45, 6, 0, 19};
	vector<int> a2 = {1, 10, 5, 2, 7};
	vector<int> a3 = {1, 11, 100, 1, 0, 200, 3, 2, 1, 250};
    int X1 = 51;
	int X2 = 9;
	int X3 = 280;
    cout<<SmallestSubarray(a1, X1)<<endl;
    cout<<SmallestSubarray(a2, X2)<<endl;
    cout<<SmallestSubarray(a3, X3)<<endl;
    return 0;
}

