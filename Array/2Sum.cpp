/*
Given a sorted array and a number ‘c’ . find pair of numbers such that a+b=c
*/
#include <iostream>
#include <vector>
using namespace std;

void TwoSum(vector<int> &a, int c)
{
	int N = a.size();
	int i = 0, j = N-1;
	while(i < j)
	{
		int S = a[i]+a[j];
		if(S > c)
			j--;
		else if(S < c)
			i++;
		else
		{
			cout<<a[i]<<" + "<<a[j]<<" = "<<c<<endl;
			i++,j--;
		}
	}
}

int main()
{
    vector<int> a = {24, 29, 42, 51, 53, 62, 83, 84, 96, 98};
    int c = 104;
    TwoSum(a, c);
	return 0;
}
