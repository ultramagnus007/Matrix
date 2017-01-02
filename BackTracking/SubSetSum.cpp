/*
Subset sum problem is to find subset of elements that are selected from a given 
set whose sum adds up to a given number K. We are considering the set contains 
non-negative values. It is assumed that the input set is unique 
(no duplicates are presented).
*/
#include <iostream>
#include <vector>
using namespace std;

void print(vector<int> &ans, int k)
{
	for(int i = k-1; i >= 0; i--)
		cout<<ans[i]<<" ";
	cout<<endl;
}


void SubSetSum(vector<int> &a, vector<int> &ans, int SUM, int k, int i)
{
	if(SUM==0)
	{
		print(ans, k);
		return ;
	}
	if(i < 0 || SUM < 0)
		return;
	ans[k] = a[i];
	SubSetSum(a, ans, SUM-a[i], k+1, i-1);
	SubSetSum(a, ans, SUM, k, i-1);
}

void SubSetDupSum(vector<int> &a, vector<int> &ans,int SUM, int k, int i)
{
	if(SUM==0)
	{
		print(ans, k);
		return ;
	}
	if(i < 0 || SUM < 0)
		return;
	ans[k] = a[i];
	SubSetDupSum(a, ans, SUM-a[i], k+1, i);
	SubSetDupSum(a, ans, SUM, k, i-1);
}

int main()
{
    vector<int> a{10, 7, 5, 18, 12, 20, 15};
    int SUM = 35;
	int N = a.size();
	vector<int> ans(N);
	cout<<"Without Duplicate\n";
	SubSetSum(a, ans, SUM, 0, N-1);
	cout<<"With Duplicate\n";
	SubSetDupSum(a, ans, SUM, 0, N-1);
	return 0;
}
