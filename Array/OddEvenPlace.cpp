/*
Given an Array equal no of odd and even number.
arrange them such that odd numbers are at odd position and even numbers are at even position.
*/

#include <iostream>
#include <vector>
using namespace std;




int main()
{
    vector<int> a = {25, 54, 68, 97, 99, 67, 44, 66, 70, 71};
    int N = a.size();
	int eao = 1;
	int oae = 0;
	while(true)
	{
		while(eao < N && a[eao]%2==1)
			eao+=2;
		while(oae < N && a[oae]%2==0)
			oae+=2;
		if(eao < N && oae < N)
			swap(a[eao], a[oae]);
		else
			break;
	}
	for(auto &x:a)
		cout<<x<<" ";
	cout<<endl;
	return 0;
}
