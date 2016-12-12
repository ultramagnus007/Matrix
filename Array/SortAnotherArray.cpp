/*
Given two arrays A1[] and A2[], sort A1 in such a way that the relative order among the elements will be same as those are in A2. For the elements not present in A2, append them at last in sorted order.
Input: A1[] = {2, 1, 2, 5, 7, 1, 9, 3, 6, 8, 8}
       A2[] = {2, 1, 8, 3}
*/

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;




class Compare
{
	private:
	map<int, int> M;
	public:
	Compare(vector<int> &a);
	bool operator()(const int &n1, const int &n2) const;
};
Compare::Compare(vector<int> &a)
{
	for(int i = 0; i < a.size(); i++)
		M[a[i]] = i;
}
bool Compare::operator()(const int &n1, const int &n2) const
{
			map<int, int>::const_iterator it1 = M.find(n1);
			map<int, int>::const_iterator it2 = M.find(n2);
			if(it1 != M.end() && it2 != M.end())
				return it1->second < it2->second;
			if(it1 == M.end() && it2 == M.end())
				return n1 < n2;
			if(it1 == M.end())
				return false;
			if(it2 == M.end())
				return true;
}

int main()
{
	vector<int> A1 = {2, 1, 2, 5, 7, 1, 9, 3, 6, 8, 8};
	vector<int> A2 = {2, 1, 8, 3};

	Compare cmp(A2);
	sort(A1.begin(), A1.end(), cmp);
	for(auto &x: A1)
		cout<<x<<" ";
	cout<<endl;

	return 0;
}
