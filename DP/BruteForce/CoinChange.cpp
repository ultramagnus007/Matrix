/*
Given a value N, if we want to make change for N cents, and we have infinite supply of each of S = { S1, S2, .. , Sm} valued coins, how many ways can we make the change? The order of coins doesn’t matter.

For example, for N = 4 and S = {1,2,3}, there are four solutions: {1,1,1,1},{1,1,2},{2,2},{1,3}. So output should be 4. For N = 10 and S = {2, 5, 3, 6}, there are five solutions: {2,2,2,2,2}, {2,2,3,3}, {2,2,6}, {2,3,5} and {5,5}. So the output should be 5.
*/

#include <iostream>
#include <vector>
using namespace std;

//done mistake
int CoinChange(vector<int> &a, int i, int C)
{
	if(C==0)
		return 1;
	if(i < 0 || C < 0)
		return 0;
	return CoinChange(a, i-1, C)+ CoinChange(a, i, C-a[i]);
}


int main()
{
	//int C = 4;
	//vector<int> a = {1, 2, 3};
	int C = 10;
	vector<int> a = {2, 5, 3, 6};
	cout<<CoinChange(a, a.size()-1, C)<<endl;

	return 0;
}
