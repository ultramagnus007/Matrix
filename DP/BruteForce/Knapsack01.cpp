/*
Given weights and values of n items, put these items in a knapsack of capacity W to get the maximum total value in the knapsack. 
*/
#include <iostream>
using namespace std;

int V[] = {60, 100, 120};
int W[] = {10, 20, 30};
int N = sizeof(V)/sizeof(int);
const int  C = 50;



int Knapsack(int C, int i)
{
	if(i < 0 || C <= 0)
		return 0;
	return max(Knapsack(C, i-1), (C-W[i]>=0?V[i]:0)+Knapsack(C-W[i], i-1));
}

int main()
{
	cout<<Knapsack(C, N-1)<<endl;
	return 0;
}
