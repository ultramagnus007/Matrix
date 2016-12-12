#include <iostream>
using namespace std;


int Binomial(int N, int K)
{
	if(N < K)
		return 0;
	if(N==K)
		return 1;
	if(K==1)
		return N;
	return Binomial(N-1, K)+Binomial(N-1, K-1);
}

int main()
{
        int N = 10;
        int K = 7;
        cout<<Binomial(10, 7)<<endl;
        return 0;
}

