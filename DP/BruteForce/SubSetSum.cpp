/*
Given a set of non-negative integers, and a value sum, determine if there is a subset of the given set with sum equal to given sum.
Examples: set[] = {3, 34, 4, 12, 5, 2}, sum = 9
Output:  True  //There is a subset (4, 5) with sum 9.
*/
#include <iostream>
#include <vector>
using namespace std;



bool SubSetSum(const vector<int> &a, int S, int i)
{
	if(S==0)	
		return true;
	if(i<0 || S < 0)
		return false;
	return SubSetSum(a, S, i-1) || SubSetSum(a, S-a[i], i-1);

}

int main()
{
	vector<int> a = {3, 34, 4, 12, 5, 2};
	int S = 9;
	if(SubSetSum(a, S, a.size()-1))
		cout<<"YES"<<endl;
	else
		cout<<"NO"<<endl;
	return 0;
}
