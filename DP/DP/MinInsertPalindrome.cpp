#include <iostream>
#include <vector>
#include <cstring>
using namespace std;


int MinInsert(const char *a)
{
	int N = strlen(a);
	vector<vector<int>> table(N);
	for(auto &v: table)
		v.resize(N, 0);
	for(int gap = 1; gap < N; gap++)
	{
		for(int i = 0; i+gap < N; i++)
		{
			int lo = i;
			int hi = i+gap;
			if(a[lo] == a[hi])
			table[lo][hi] = (lo+1<=hi-1)?table[lo+1][hi-1]:0;
			else
			table[lo][hi] = 1+min(table[lo+1][hi], table[lo][hi-1]);
		}
	}
	return table[0][N-1];
}

int main()
{
        char a1[] = "geeks";
	char a2[] = "abcde"; 
        cout<<MinInsert(a1)<<endl;
        cout<<MinInsert(a2)<<endl;
        return 0;
}

