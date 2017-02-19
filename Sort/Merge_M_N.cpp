//Given two arrays of ints of size m and m+n in sorted order. merge it inplace. Famous problem. (Code)

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
using namespace std;

void Merge(vector<int> &a, vector<int> &b)
{
	int m = a.size();
	int i = 0, int j = 0;
	while(i < m)
	{
		if(a[i] > b[j])
			swap(a[i], b[j++]);
		else
			i++;
	}
	int k = 0;
	while()
	{

	}
}
int main()
{
	int m = 25;
	int n = 15;
	srand(time(NULL));
	vector<int> a(m);
	vector<int> b(m+n);
	for(auto &x: a)
		x = rand()%100;
	for(auto &x: b)
		x = rand()%100;
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	Merge(a, b);
	for(const auto &x: a)
		cout<<x<<" ";
	for(const auto &x: b)
		cout<<x<<" ";
	return 0;
}
