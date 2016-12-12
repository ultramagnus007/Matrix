#include <iostream>
#include <vector>
#include <cstring>
using namespace std;


int LCSUB(const char *a, const char *b)
{
	int N1 = strlen(a);
	int N2 = strlen(b);
	vector<vector<int>> table(N1);
	for(auto &v: table)
		v.resize(N2, 0);
	int ans = 0;
	for(int i = 0; i < N1; i++)
	{
		for(int j = 0; j < N2; j++)
		{
			if(a[i] == b[j])
				table[i][j] = 1+((i-1>=0&&j-1>=0)?table[i-1][j-1]:0);
			ans = max(ans, table[i][j]);	
		}
	}
	return ans;
}

int main()
{
        char a[] = "OldSite:GeeksforGeeks.org";
        char b[] = "NewSite:GeeksQuiz.com";
        cout<<LCSUB(a, b)<<endl;
        return 0;
}

