/*
Given an array of integers , an iteration is defined as calculating the differences of adjacent elements of the array. For example: an iteration of the array {8,4,3}

is {4-8,3-4} = {-4,-1}. on the next iteration the array becomes {-1-(-4)} = {3}, on further iterations, the array remains as {3}.
*/

#include <iostream>
#include <vector>
using namespace std;

int diffAdjacent(vector<int> &a)
{
	int N = a.size();
	if(N==0)
		return 0;
	while(N > 1)
	{
		for(int i = 0; i < N-1; i++)
			a[i] = a[i+1]-a[i];
		N--;
	}
	return a[0];
}

int main()
{
	vector<int> a = {5,6,3,9,-1};


	cout<<diffAdjacent(a)<<endl;

	return 0;
}
