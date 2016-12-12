/*divide a set of positive integers  into 2 sets such that difference of their sum is equal

from wiki
p(i, j) be True if a subset of { x1, ..., xj } sums to i and False otherwise.
p(i, j) is true
if p(i,j-1) is true
or p(i-a[j], j-1) is true

*********This Algorithm works only for positive set of intergers does not work if any -ve interger in set*************
*/

#include <iostream>
#include <vector>
using namespace std;



int main()
{
	vector<int> a = {3, 1, 1, 2, 2, 1};
	int totalSum = 0;	
	int N = a.size();
	for(int i = 0; i < N; i++)
		totalSum+=a[i];
	int S = totalSum/2;
	vector<vector<bool>> table(N+1);
	for(auto &v : table)
		v.resize(S, false);

	for(int i = 0; i < N; i++)
		table[i][0] = true;

	for(int i = 1; i<=N; i++)	
	{
		for(int j = 1; j <= S; j++)
		{
			int x = j-a[i-1];
			if(x>=0)
			table[i][j] = table[i-1][j] || table[i-1][x];
			else
			table[i][j] = table[i-1][j];
		}
	}


    if(table[N][S] == true)
        cout<<"partition is possible\n";
    else
        cout<<"partition is not possible\n";
	#if 0
	int mindiff = totalSum;
	for(int k=S; k>=0;k++)
	{
		if(table[N][k])
		{
			mindiff = totalSum-2*k;
			break;
		}
	}
	cout<<mindiff<<endl;
	#endif
	return 0;
}
