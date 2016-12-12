#include <iostream>
#include <vector>
using namespace std;


int Binomial(int N, int K)
{
	if(K > N)
		return 0;
	vector<vector<int>> a(N+1);
	for(auto &v: a)
		v.resize(K+1, 1);
	for(int j = 1; j <= K; j++)
	{
		a[j][j] = 1;
		for(int i = j+1; i <= N; i++)
		{
			a[i][j] = a[i-1][j]+a[i-1][j-1];
		}
	}
	return a[N][K];
}

int main()
{
        int N = 10;
        int K = 7;
        cout<<"Enter N and K\n";
        cin>>N>>K;
        cout<<Binomial(N, K)<<endl;
        return 0;
}

