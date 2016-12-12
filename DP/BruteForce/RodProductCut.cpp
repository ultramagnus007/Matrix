/*
Given a rope of length n meters, cut the rope in different parts of integer lengths in a way that maximizes product of lengths of all parts. You must make at least one cut. Assume that the length of rope is more than 2 meters.
*/

#include <iostream>
using namespace std;

int RodProductCut(int N)
{
	if(N<=4)
		return N;
	int ans = N;
	for(int i = 2; i <= N-2; i++)
		ans = max(ans, RodProductCut(i)*RodProductCut(N-i));
	return ans;
}

int RPC(int N)
{
	if(N<=4)
		return N;
	int ans = 1;
	while(N>4)
	{
		ans*=3;
		N-=3;
	}
	ans*=N;
	return ans;
}

int main()
{
	int N = 10;
	cout<<RodProductCut(N)<<endl;
	cout<<RPC(N)<<endl;
	return 0;
}


