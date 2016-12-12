/*
Given an array of integers where each element represents the max number of steps that can be made forward from that element. Write a function to return the minimum number of jumps to reach the end of the array (starting from the first element). If an element is 0, then cannot move through that element.
Example:
Input: arr[] = {1, 3, 5, 8, 9, 2, 6, 7, 6, 8, 9}
Output: 3 (1-> 3 -> 8 ->9)
*/


#include <iostream>
#include <vector>
using namespace std;

int JumpMin(vector<int> &a)
{
	int N  = a.size();
	vector<int> table(N, 0);
	for(int i = 1; i < N; i++)
	{
		table[i] = 10000;
		for(int j = 0; j < i; j++)
		{
			if(i <= j+a[j])
			table[i] = min(table[i], 1+table[j]);
		}
	}
	if(table[N-1]< 10000)
		return  table[N-1];
	else
		return 0;
}

int main()
{
	vector<int> a = {1, 3, 5, 8, 9, 2, 6, 7, 6, 8, 9};
	cout<<JumpMin(a)<<endl;
	return 0;
}
