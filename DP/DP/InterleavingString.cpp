#include <iostream>
#include <cstring>
#include <vector>
using namespace std;


void test(const char *a, const char *b, const char *c)
{
	int N1 = strlen(a);
	int N2 = strlen(b);
	int N3 = strlen(c);
	if(N3 != N1+N2)
	{
		cout<<"NO"<<endl;
		return;
	}
	vector<vector<bool>> table(N1+1);
	for(auto &v: table)
		v.resize(N2+1, false);
	table[0][0] = true;
	for(int i = 1; i <= N1; i++)
		table[i][0] = table[i-1][0] && (a[i-1]==c[i-1]);
	for(int i = 1; i <= N2; i++)
		table[0][i] = table[0][i-1] && (b[i-1]==c[i-1]);
	for(int i = 1; i <= N1; i++)
	{
		for(int j = 1; j <= N2; j++)
	    {
			/*******Mistake******/
			//table[i][j] = (table[i][j-1] && (b[j-1]==c[i+j-2])) || 
			//				(table[i-1][j] && (a[i-1]==c[i+j-2]));
			table[i][j] = (table[i][j-1] && (b[j-1]==c[i+j-1])) || 
							(table[i-1][j] && (a[i-1]==c[i+j-1]));

		}
	}
	if(table[N1][N2])
		cout<<"YES\n";
	else
		cout<<"NO\n";
	#if 0
	for(int i = 0; i <= N1; i++)
	{
		for(int j = 0; j <= N2; j++)
		{
			cout<<table[i][j]<<" ";
		}
		cout<<endl;
	}
	#endif
}

int main()
{
    test("XXY", "XXZ", "XXZXXXY");
    test("XY" ,"WZ" ,"WZXY");
    test ("XY", "X", "XXY");
    test ("YX", "X", "XXY");
    test ("XXY", "XXZ", "XXXXZY");
    return 0;
}

