#include <iostream>
#include <vector>
using namespace std;


void SubArraySum(vector<int> &a, int X)
{
	int N = a.size();
	int i = 0;
	int j = 0;

	int S = 0;
	while(j < X)
	{
		if(S<X)
			S+=a[j++];
		else if(S > X)
			S-=a[i++];
		else
			break;
	}
	for(int k = i; k < j; k++)
		cout<<a[k]<<" ";
	cout<<endl;
}
int main()
{
    vector<int> a = {15, 2, 4, 8, 9, 5, 10, 23};
    int N = a.size();
    int X = 23;
    SubArraySum(a, X);
    return 0;
}
