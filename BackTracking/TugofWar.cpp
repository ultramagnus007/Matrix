/*
given a set of n integers, divide the set in two subsets of n/2 sizes each such that the difference of the sum of two subsets is as minimum as possible. If n is even, then sizes of two subsets must be strictly n/2 and if n is odd, then size of one subset must be (n-1)/2 and size of other subset must be (n+1)/2.

For example, let given set be {3, 4, 5, -3, 100, 1, 89, 54, 23, 20}, the size of set is 10. Output for this set should be {4, 100, 1, 23, 20} and {3, 5, -3, 89, 54}. Both output subsets are of size 5 and sum of elements in both subsets is same (148 and 148).
Let us consider another example where n is odd. Let given set be {23, 45, -34, 12, 0, 98, -99, 4, 189, -1, 4}. The output subsets should be {45, -34, 12, 98, -1} and {23, 0, -99, 4, 189, 4}. The sums of elements in two subsets are 120 and 121 respectively.
*/

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;


void print(vector<int> &a, vector<bool> &ans, bool b)
{
	for(int i = 0; i < a.size(); i++)
	{
		if(ans[i]==b)
			cout<<a[i]<<" ";
	}
	cout<<endl;
}
void TugofWar(vector<int> &a, int TS, vector<bool> &isfirst,
						int &S, vector<bool> &ans, int &ansS,
						int &size, int i)
{

	if(size == a.size()/2 || size == a.size()/2+1)
	{
		if(abs(TS-2*ansS) > abs(TS-2*S))
		{
			ansS = S;
			for(int i = 0; i < isfirst.size(); i++)
				ans[i] = isfirst[i];
		}

	}
	if(i < 0)
		return;
	//including a[i]
	size++;
	S+=a[i];
	isfirst[i] = true;
	TugofWar(a, TS, isfirst, S, ans, ansS,  size, i-1);
	size--;
	S-=a[i];
	isfirst[i] = false;

	//not including a[i]
	TugofWar(a, TS, isfirst, S, ans, ansS,  size, i-1);
}
int main()
{
	vector<int> a {3, 4, 5, -3, 100, 1, 89, 54, 23, 20};
	//vector<int> a {23, 45, -34, 12, 0, 98, -99, 4, 189, -1, 4};

	int S = 0;		
	vector<bool> isfirst(a.size(), false);
	vector<bool> ans(a.size(), false);
	int ansS = 0;
	int TS = 0;
	int size = 0;
	for(auto &x: a)
		TS+=x;
	TugofWar(a, TS, isfirst, S, ans, ansS,  size, a.size()-1);
	cout<<ansS<<endl;
	print(a, ans, true);
	cout<<TS-ansS<<endl;
	print(a, ans, false);
	return 0;
}
