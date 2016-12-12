/*
Remove minimum elements from either side such that 2*min becomes more than max

Given an unsorted array, trim the array such that twice of minimum is greater than maximum in the trimmed array. Elements should be removed either end of the array.

Number of removals should be minimum.

Examples:

arr[] = {4, 5, 100, 9, 10, 11, 12, 15, 200}
Output: 4
We need to remove 4 elements (4, 5, 100, 200)
so that 2*min becomes more than max.


arr[] = {4, 7, 5, 6}
Output: 0
We don't need to remove any element as 
4*2 > 7 (Note that min = 4, max = 8)

arr[] = {20, 7, 5, 6}
Output: 1
We need to remove 20 so that 2*min becomes
more than max

arr[] = {20, 4, 1, 3}
Output: 3
We need to remove any three elements from ends
like 20, 4, 1 or 4, 1, 3 or 20, 3, 1 or 20, 4, 1
*/

#include <iostream>
#include <climits>
#include <vector>
using namespace std;

pair<int, int> findMinMax(const vector<int> &a, int lo, int hi)
{
	int minval = INT_MAX;
	int maxval = INT_MIN;
	for(int i = lo; i <= hi; i++)
	{
		minval = min(minval, a[i]);
		maxval = max(maxval, a[i]);
	}
	return pair<int, int>(minval, maxval);
}

int RemoveElements(const vector<int> &a, int lo, int hi)
{
	if(lo>=hi)
		return 0;
	pair<int, int> minmax = findMinMax(a, lo, hi);
	if(2*minmax.first > minmax.second)
		return 0;
	return 1+min(RemoveElements(a, lo+1, hi), RemoveElements(a, lo, hi-1));
}
int main()
{

	vector<int> a1 = {4, 5, 100, 9, 10, 11, 12, 15, 200};
	vector<int> a2 = {4, 7, 5, 6};
	vector<int> a3 = {20, 7, 5, 6};
	vector<int> a4 = {20, 4, 1, 3};
	
	cout<<RemoveElements(a1, 0, a1.size()-1)<<endl;
	cout<<RemoveElements(a2, 0, a2.size()-1)<<endl;
	cout<<RemoveElements(a3, 0, a3.size()-1)<<endl;
	cout<<RemoveElements(a4, 0, a4.size()-1)<<endl;

	return 0;
}






