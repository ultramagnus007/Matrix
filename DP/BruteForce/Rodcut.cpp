/*
Given a rod of length n inches and an array of prices that contains prices of all pieces of size smaller than n. Determine the maximum value obtainable by cutting up the rod and selling the pieces.
*/
#include <iostream>
#include <vector>
using namespace std;


int RodCut(vector<int> &a, int size)
{
	int maxCost = a[size-1];
	for(int i = 1; i < size; i++)
		maxCost = max(maxCost, RodCut(a, i)+RodCut(a, size-i));	
	return maxCost;
}


int main()
{
	vector<int> a = {1, 5, 8, 9, 10, 17, 17, 20};

	cout<<RodCut(a, a.size())<<endl;
	return 0;
}
