/*
Given a set of non-negative integers, and a value sum, determine if there is a subset of the given set with sum equal to given sum.
Examples: set[] = {3, 34, 4, 12, 5, 2}, sum = 9
Output:  True  //There is a subset (4, 5) with sum 9.
*/

#include <iostream>
#include <vector>
using namespace std;

bool SubSetSum(const vector<int> &a, int S)
{
	int N = a.size();
	vector<vector<bool>> table(N+1);
	for(auto &v: table)
		v.resize(S+1, false);
	for(int i = 0; i <= N; i++)
		table[i][0] = true;
	for(int i = 1; i <= N; i++)
	{
		for(int j = 1; j <= S; j++)
		{
			if(j-a[i]>=0)
			table[i][j] = table[i-1][j] || table[i-1][j-a[i]];
			else
			table[i][j] = table[i-1][j];
		}
	}
	return table[N][S];
}

int main()
{
        vector<int> a = {3, 34, 4, 12, 5, 2};
        int S = 9;
        if(SubSetSum(a, S))
                cout<<"YES"<<endl;
        else
                cout<<"NO"<<endl;
	return 0;
}
