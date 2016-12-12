#include <iostream>
using namespace std;

int Fibonacci(int N)
{
	if(N<2)
		return N;
	int f0 = 0;
	int f1 = 1;
	int f2;
	for(int i = 2; i <= N; i++)
	{
		f2 = f0+f1;
		f0 = f1;
		f1 = f2;	
	}
	return f2;
}

int main()
{
        int N = 45;
        cout<<Fibonacci(N)<<endl;
        return 0;
}
