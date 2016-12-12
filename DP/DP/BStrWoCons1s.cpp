/*
Given a positive integer N, count all possible distinct binary strings of length N such that there are no consecutive 1′s.
*/


#include <iostream>
using namespace std;


int countString(int N)
{
	if(N<=1)
		return N+1;
	int f0 = 1;
	int f1 = 2;
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
    int N;
    cout<<"Enter the number\n";
    cin>>N;
    cout<<countString(N)<<endl;
    return 0;
}

