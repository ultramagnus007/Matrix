/*
Given a rope of length n meters, cut the rope in different parts of integer lengths in a way that maximizes product of lengths of all parts. You must make at least one cut. Assume that the length of rope is more than 2 meters.
*/
#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int RodProductCut(int N)
{
	if(N<=4)
		return N;
	vector<int> table(N+1, 0);
	for(int i = 1; i <= N; i++)
	{
		table[i] = i;
		for(int j = 1; j < i; j++)
			table[i] = max(table[i], table[j]*table[i-j]);
	}
	return table[N];
}

int main()
{
	int N = 10;
        cout<<"Maximum Obtainable product = "<<RodProductCut(N)<<endl;
	return 0;
}
