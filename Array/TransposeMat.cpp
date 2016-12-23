/*In-place matrix transposition
Logic
How can we generate permutation cycles? Number of elements in both the matrices are constant, given by N = R * C, where R is row count and C is column count. An element at location ol (old location in R x C matrix), moved to nl (new location in C x R matrix). We need to establish relation between ol, nl, R and C. Assume ol = A[or][oc]. In C/C++ we can calculate the element address as,

ol = or x C + oc (ignore base reference for simplicity)

It is to be moved to new location nl in the transposed matrix, say nl = A[nr][nc], or in C/C++ terms

nl = nr x R + nc (R - column count, C is row count as the matrix is transposed)

Observe, nr = oc and nc = or, so replacing these for nl,

nl = oc x R + or -----> [eq 1]

after solving for relation between ol and nl, we get

ol     = or x C     + oc
ol x R = or x C x R + oc x R
       = or x N     + oc x R    (from the fact R * C = N)
       = or x N     + (nl - or) --- from [eq 1]
       = or x (N-1) + nl

OR,

nl = ol x R - or x (N-1)

Note that the values of nl and ol never go beyond N-1, so considering modulo division on both the sides by (N-1), we get the following based on properties of congruence,

nl mod (N-1) = (ol x R - or x (N-1)) mod (N-1)
             = (ol x R) mod (N-1) - or x (N-1) mod(N-1)
             = ol x R mod (N-1), since second term evaluates to zero
nl = (ol x R) mod (N-1), since nl is always less than N-1

*/




/*
output
    1, 6, 11, 16,
    2, 7, 12, 17,
    3, 8, 13, 18,
    4, 9, 14, 19,
    5, 10, 15, 20,
*/
#include <iostream>
#include <vector>
using namespace std;

void print(vector<int> &a, int R, int C)
{
	for(int i = 0; i < R; i++)
	{
		for(int j = 0; j < C; j++)
		{
			cout<<a[i*C+j]<<" ";
			if(a[i*C+j] < 10)
			cout<<" ";
		}
		cout<<endl;
	}
	cout<<endl;
}

void transposeBruteForce(vector<int> &a, int R, int C)
{
	vector<int> b(a.size(), 0);
	for(int i = 0; i < R; i++)
	{
		for(int j = 0; j < C; j++)
		{
			b[j*R+i] = a[i*C+j];
		}
	}
	for(int i =0; i < b.size(); i++)
		a[i] = b[i];
}

void transposeOptimized(a, R, C)
{


}

int main()
{
	const int R = 4;
	const int C = 5;
	vector<int> a  =
    {
		1,  2,  3,  4,  5,
		6,  7,  8,  9, 10,
	    11,12, 13, 14, 15,
		16,17, 18, 19, 20
    };
	print(a, R, C);
	transposeOptimized(a, R, C);
	//transposeBruteForce(a, R, C);
	print(a, C, R);
	return 0;
}
