#include <iostream>
#include <cstring>
using namespace std;



bool interleave(const char *a, const char *b, const char *c, int i, int j, int k)
{
	if(i==-1 && j == -1 && k == -1)
		return true;
	if(k<0)
		return false;
	if(i>=0 && a[i] == c[k])
		return interleave(a, b, c, i-1, j, k-1);
	if(j>=0 && b[j] == c[k])
		return interleave(a, b, c, i, j-1, k-1);
	return false;
}

void test(const char *a, const char *b, const char *c)
{

	int n1 = strlen(a);
	int n2 = strlen(b);
	int n3 = strlen(c);
	if(n3 != n1+n2)
	{
		cout<<"NO INTERLEAVE"<<endl;
		return;
	}
	if(interleave(a, b, c, n1-1, n2-1, n3-1))
		cout<<"YES INTERLEAVE"<<endl;
	else
		cout<<"NO INTERLEAVE"<<endl;
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

