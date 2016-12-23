/*
Given an array which is sorted, but after sorting some elements are moved to either of the adjacent positions

For example consider the array {2, 3, 10, 4, 40}, 4 is moved to next position and 10 is moved to previous position.

Example:

Input: arr[] =  {10, 3, 40, 20, 50, 80, 70}, key = 40
Output: 2 
Output is index of 40 in given array

Input: arr[] =  {10, 3, 40, 20, 50, 80, 70}, key = 90
Output: -1
-1 is returned to indicate element is not present
*/

#include <iostream>
#include <vector>
using namespace std;

int search(const vector<int> &a, int key)
{
	int lo = 0, hi = a.size()-1;
	while(lo <= hi)
	{
		int mid = (lo+hi)/2;
		if(a[mid] == key)
			return mid;
		if(mid+1 <= hi && a[mid+1] == key)
			return mid+1;
		if(mid-1 >= lo && a[mid-1] == key)
			return mid-1;
		if(key < a[mid])
			hi = mid-2;
		else 
			lo = mid+2;
	}
	return -1;
}


int main()
{
	vector<int> a =  {10, 3, 40, 20, 50, 80, 70};
	for(auto x: a)
		cout<<search(a, x)<<endl;
	int k = 90;
	cout<<search(a, k)<<endl;
	return 0;
}
