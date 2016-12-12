#include <iostream>
#include <vector>
using namespace std;

int MaxContiguousSubarray(const vector<int> &a)
{
	int maxconti = 0;
	int curconti = 0;
	int si = 0;
	int msi = 0;
	int mei = 0;
	for(int i = 0; i < a.size(); i++)
	{
		curconti += a[i];	
		if(curconti < 0)
		{
			curconti = 0;
			si = i+1;
		}
		if(curconti > maxconti)
		{
			maxconti = curconti;
			msi = si;
			mei = i;
		}
	}
	for(int i = msi; i <= mei ; i++)
		cout<<a[i]<<" ";
	cout<<endl;
	return maxconti;	
}

int main()
{
	vector<int> a1 =  {-2, -3, 4, -1, -2, 1, 5, -3};
	vector<int> a2 = {22, -27, 38, -34, 49, 40, 13, -44, -13, 28, 46, 7, -26, 42,
        29, 0, -6, 35, 23, -37, 10, 12, -2, 18, -12, -49, -10, 37, -5, 17,
        6, -11, -22, -17, -50, -40, 44, 14, -41, 19, -15, 45, -23, 48, -1,
        -39, -46, 15, 3, -32, -29, -48, -19, 27, -33, -8, 11, 21, -43, 24,
        5, 34, -36, -9, 16, -31, -7, -24, -47, -14, -16, -18, 39, -30, 33,
        -45, -38, 41, -3, 4, -25, 20, -35, 32, 26, 47, 2, -4, 8, 9, 31, -28,
        36, 1, -21, 30, 43, 25, -20, -42};

	cout<<MaxContiguousSubarray(a1)<<endl;
	cout<<MaxContiguousSubarray(a2)<<endl;
	return 0;
}
