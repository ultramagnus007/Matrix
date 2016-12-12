/*
The longest Increasing Subsequence (LIS) problem is to find the length of the longest subsequence of a given sequence such that all elements of the subsequence are sorted in increasing order. For example, length of LIS for { 10, 22, 9, 33, 21, 50, 41, 60, 80 } is 6 and LIS is {10, 22, 33, 50, 60, 80}. 
*/

#include <iostream>
#include <vector>
using namespace std;


int LIS(vector<int> &a)
{
	int N = a.size();
	vector<int> table(N, 0);
	int lis = 0;

	for(int i = 0; i < N; i++)
	{
		int tlis = 1;
		for(int j = 0; j < i; j++)
		{
			if(a[i] >= a[j])
				tlis = max(tlis, 1+table[j]);
		}
		table[i] = tlis;
		lis = max(lis, tlis);
	}
	return lis;
}

int main()
{
	vector<int> a = {10, 22, 9, 33, 21, 50, 41, 60, 80};
	cout<<LIS(a)<<endl;
	return 0;
}
