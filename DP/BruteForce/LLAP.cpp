/*
Given a set of numbers, find the Length of the Longest Arithmetic Progression (LLAP) in it.

Examples:

set[] = {1, 7, 10, 15, 27, 29}
output = 3
The longest arithmetic progression is {1, 15, 29}

set[] = {5, 10, 15, 20, 25, 30}
output = 6
The whole set is in AP
*/

#include <iostream>
#include <vector>
using namespace std;

//assuming sorted otherwise sort
int find(const vector<int> &a, int x, int lo, int hi)
{
	while(lo <= hi)
	{
		int mid = (lo+hi)/2;
		if(a[mid] < x)
			lo = mid+1;
		else if(a[mid] > x)
			hi = mid-1;
		else
			return mid;
	}
	return -1;
}

int LLAP(const vector<int> &a)
{
	int maxllap = 0;
	for(int i = 0;  i < a.size(); i++)
	{
		for(int j = i+1; j < a.size(); j++)
		{
			int d = a[j] - a[i];
			int index  = j;
			int size = 2;
			int D = d;
			while(true)
			{
				index = find(a, D+a[j], index+1, a.size()-1);
				D+=d;
				if(index != -1)
					size++;
				else
					break;
			}
			maxllap = max(maxllap, size);
		}
	}
	return maxllap;
}

int main()
{
	vector<int> a1 = {1, 7, 10, 15, 27, 29};
	vector<int> a2 = {5, 10, 15, 20, 25, 30};
	cout<<LLAP(a1)<<endl;
	cout<<LLAP(a2)<<endl;
	return 0;
}
