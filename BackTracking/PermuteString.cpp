#include <iostream>
#include <cstring>
using namespace std;

void permute(char * a, int N, int i)
{
	if(i == N)
	{
		cout<<a<<endl;
		return;
	}
	for(int k = i; k < N; k++)
	{
		swap(a[k], a[i]);
		permute(a, N, i+1);
		swap(a[k], a[i]);
	}
}


int main()
{
	char a[] = "ABCD";
	int N = strlen(a);
	permute(a , N, 0);
	return 0;
}
