/*
Given n dice each with m faces, numbered from 1 to m, find the number of ways to get sum X. X is the summation of values on each face when all the dice are thrown.
*/
#include <iostream>
using namespace std;


int FindWays(int m, int n, int X)
{
	if(X==0 && n==0)
		return 1;
	if(n==0 || X < 0)
		return 0;
	int ways = 0;
	for(int i = 1; i <= m; i++)	
		ways+= FindWays(m, n-1, X-i);
	return ways;
}



int main()
{
        cout << FindWays(4, 2, 1) << endl;
        cout << FindWays(2, 2, 3) << endl;
        cout << FindWays(6, 3, 8) << endl;
        cout << FindWays(4, 2, 5) << endl;
        cout << FindWays(4, 3, 5) << endl;
        return 0;
}

