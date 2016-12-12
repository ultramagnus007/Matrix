/*
Dynamic Programming | Set 8 (Matrix Chain Multiplication)

Given a sequence of matrices, find the most efficient way to multiply these matrices together. The problem is not actually to perform the multiplications, but merely to decide in which order to perform the multiplications.

We have many options to multiply a chain of matrices because matrix multiplication is associative. In other words, no matter how we parenthesize the product, the result will be the same. For example, if we had four matrices A, B, C, and D, we would have:

    (ABC)D = (AB)(CD) = A(BCD) = ....

However, the order in which we parenthesize the product affects the number of simple arithmetic operations needed to compute the product, or the efficiency. For example, suppose A is a 10 × 30 matrix, B is a 30 × 5 matrix, and C is a 5 × 60 matrix. Then,

    (AB)C = (10×30×5) + (10×5×60) = 1500 + 3000 = 4500 operations
    A(BC) = (30×5×60) + (10×30×60) = 9000 + 18000 = 27000 operations.
*/

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int MatrixChain(const vector<int> &a)
{
	int N  = a.size();
	vector<vector<int>> table(N);
	for(auto &v: table)
		v.resize(N, 0);
	for(int gap = 2; gap < N; gap++)
	{
		for(int i = 0; i+gap < N; i++)
		{
			int lo = i;
			int hi = lo+gap;
			table[lo][hi] = INT_MAX;
			for(int k = i+1; k < hi; k++ )
				table[lo][hi] = min(table[lo][hi], a[lo]*a[k]*a[hi]+table[lo][k]+table[k][hi]);	
		}
	}
	return table[0][N-1];
}

int main()
{
        vector<int> a1 = {40, 20, 30, 10, 30};
        vector<int> a2 = {10, 20, 30, 40, 30};
        vector<int> a3 = {10, 20, 30};
        cout<<MatrixChain(a1)<<endl;
        cout<<MatrixChain(a2)<<endl;
        cout<<MatrixChain(a3)<<endl;
        return 0;
}

