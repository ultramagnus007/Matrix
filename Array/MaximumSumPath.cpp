/*
Given two sorted arrays such the arrays may have some common elements. Find the sum of the maximum sum path to reach from beginning of any array to end of any of the two arrays. We can switch from one array to another array only at common elements.

Expected time complexity is O(m+n) where m is the number of elements in ar1[] and n is the number of elements in ar2[].

Examples:

Input:  ar1[] = {2, 3, 7, 10, 12}, ar2[] = {1, 5, 7, 8}
Output: 35
35 is sum of 1 + 5 + 7 + 10 + 12.
We start from first element of arr2 which is 1, then we
move to 5, then 7.  From 7, we switch to ar1 (7 is common)
and traverse 10 and 12.

Input:  ar1[] = {10, 12}, ar2 = {5, 7, 9}
Output: 22
22 is sum of 10 and 12.
Since there is no common element, we need to take all 
elements from the array with more sum.

Input:  ar1[] = {2, 3, 7, 10, 12, 15, 30, 34}
        ar2[] = {1, 5, 7, 8, 10, 15, 16, 19}
Output: 122
122 is sum of 1, 5, 7, 8, 10, 12, 15, 30, 34

*/


#include <iostream>
#include <vector>
using namespace std;


int maxSum(const vector<int> &a1, const vector<int> &a2)
{
	int N1 = a1.size();
	int N2 = a2.size();
	int i = 0, S1 = 0;
	int j = 0, S2 = 0;
	int S = 0;
	while(i < N1 && j < N2)
	{
		if(a1[i] < a2[j])
			S1+=a1[i++];
		else if(a1[i] > a2[j])
			S2+=a2[j++];
		else
		{
			S+=a1[i]+max(S1, S2);
			i++,j++;
			S1 = 0;
			S2 = 0;
		}
	}
	while(i < N1)
		S1+=a1[i++];
	while(j < N2)
		S2+=a2[j++];
	 S+=max(S1, S2);
	return S;
}

int main()
{
    vector<int> a1 = {2, 3, 7, 10, 12};
    vector<int> a2 = {1, 5, 7, 8};

    vector<int> a3 = {10, 12};
    vector<int> a4 = {5, 7, 9};

    vector<int> a5 = {2, 3, 7, 10, 12, 15, 30, 34};
    vector<int> a6 = {1, 5, 7, 8, 10, 15, 16, 19};
    cout<<maxSum(a1, a2)<<endl;
    cout<<maxSum(a3, a4)<<endl;
    cout<<maxSum(a5, a6)<<endl;
	return 0;
}
