#include <iostream>
using namespace std;


int Fib(int N)
{
	if(N==1 || N ==0)
		return N;
	return Fib(N-1)+Fib(N-2);
}

int main()
{
	int N = 45;
	cout<<Fib(N)<<endl;
	return 0;
}
