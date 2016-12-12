/*
Given an array of integers where each element represents the max number of steps that can be made forward from that element. Write a function to return the minimum number of jumps to reach the end of the array (starting from the first element). If an element is 0, then cannot move through that element.

Example:

Input: arr[] = {1, 3, 5, 8, 9, 2, 6, 7, 6, 8, 9}
Output: 3 (1-> 3 -> 8 ->9)
*/

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int MinJump(const vector<int> &a, int pos)
{
	if(pos >= a.size()-1)
		return 0;
	int minjump = INT_MAX;
	for(int i = pos+1; i < a.size() && i <= pos+a[pos]; i++)
	{
		minjump = min(minjump, 1+MinJump(a, i));
	}
	return minjump;
}

int main()
{

	vector<int> a = {1, 3, 5, 8, 9, 2, 6, 7, 6, 8, 9};
	int ans = MinJump(a, 0);
	if(ans != INT_MAX)
		cout<<ans<<endl;
	else
		cout<<0<<endl;
	return 0;
}
