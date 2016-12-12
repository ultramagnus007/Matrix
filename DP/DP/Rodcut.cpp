/*
Given a rod of length n inches and an array of prices that contains prices of all pieces of size smaller than n. Determine the maximum value obtainable by cutting up the rod and selling the pieces.
*/

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int RodCut(const vector<int> &a)
{
	int N = a.size();
	vector<int> table(N+1, 0);
	for(int i = 1; i <= N; i++)
	{
		table[i] = a[i-1];
		for(int j = 1; j < i; j++)
			table[i] = max(table[i], table[j]+table[i-j]);
	}
	return table[N];
}


int main()
{
        vector<int> a1 = {1, 5, 8, 9, 10, 17, 17, 20};
        vector<int> a2 = {3, 5, 8, 9, 10, 17, 17, 20};
        cout<<RodCut(a1)<<endl;
        cout<<RodCut(a2)<<endl;
        return 0;
}

