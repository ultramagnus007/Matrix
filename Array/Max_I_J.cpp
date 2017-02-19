//Given array of ints. find ar[i],ar[j] such that j>i and ar[j]-ar[i] is maximum. Famous problem. (Code)
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <climits>
using namespace std;

void BruteForce(vector<int> &a)
{
	if(a.size() < 2)
		return;
	int x1, x2;
	int diff = INT_MIN;
	for(int i = 0; i < a.size()-1; i++)
	{
		for(int j = i+1; j < a.size(); j++)
		{	
			if(a[j] - a[i] > diff)
			{
				x1 = a[i];
				x2 = a[j];
				diff = a[j] - a[i];
			}
		}
	}
	cout<<x1<<" "<<x2<<endl;
}

void Optimized(vector<int> &a)
{
	if(a.size() < 2)
		return;
	int preMin = a[0];
	int x1, x2;
	int diff = INT_MIN;
	for(int j = 1; j < a.size(); j++)
	{
		if(a[j] - preMin > diff)
		{
			x1 = preMin;
			x2 = a[j];
			diff = a[j] - preMin;	
		}
		preMin = min(a[j], preMin);
	}
	cout<<x1<<" "<<x2<<endl;
}


int main()
{
	int N = 100;
	vector<int> a(N);
	srand(time(NULL));
	for(auto &x: a)
		x = rand()%100;
	BruteForce(a);
	Optimized(a);
	return 0;
}
