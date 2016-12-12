#include <iostream>
#include <cmath>
#include <cstring>
using namespace std;


void generateSubSets(char * a)
{
	int N = strlen(a);
	int num  = pow(2, N);
	int s = 0;
	int count = 0;
	for(int i = 0; i < num; i++)
	{
		int k = 1;
		cout<<"{";
		for(int j = 0; j < N; j++)
		{
			if(count & k)
				cout<<a[j];
			k=k<<1;
		}
		count++;
		cout<<"}"<<endl;
	}
}


int main()
{
    char a[] = "abcd";
    generateSubSets(a);
	return 0;
}

