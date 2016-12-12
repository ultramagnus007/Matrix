/*
Problem statement: Consider a row of n coins of values v1 . . . vn, where n is even. We play a game against an opponent by alternating turns. In each turn, a player selects either the first or last coin from the row, removes it from the row permanently, and receives the value of the coin. Determine the maximum possible amount of money we can definitely win if we move first.
*/

#include <iostream>
#include <vector>
using namespace std;


int OptimalGame(vector<int> &a, int lo, int hi)
{
	if(lo > hi)
		return 0;
	int L = a[lo]+min(OptimalGame(a, lo+2, hi), OptimalGame(a, lo+1, hi-1));
	int R = a[hi]+min(OptimalGame(a, lo+1, hi-1), OptimalGame(a, lo, hi-2));
	return max(L, R);
}

int main()
{
        vector<int> a1 = {8, 15, 3, 7};
        cout<<OptimalGame(a1, 0, a1.size()-1)<<endl;
        vector<int> a2 = {2, 2, 2, 2};
        cout<<OptimalGame(a2, 0, a2.size()-1)<<endl;
        vector<int> a3 = {20, 30, 2, 2, 2, 10};
        cout<<OptimalGame(a3, 0, a3.size()-1)<<endl;
	return 0;
}
