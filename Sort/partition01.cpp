#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>

using namespace std;

void print(const vector<int> &a)
{
	for(const int &x:a)
		cout<<x<<" ";
	cout<<endl;
}

void split(vector<int> &a)
{
	int lo = 0;
	int hi = a.size()-1;
	int pivot = 1;
	while(true)
	{
		while(lo <= hi && a[lo] < pivot)
			lo++;
		while(lo <= hi && a[hi] >= pivot)
			hi--;
		if(lo >= hi)
			break;
		else
			swap(a[lo], a[hi]);
	}
}
int main()
{
	const int N = 10;
	vector<int> a(N);
	srand(time(NULL));
	for(auto &x: a)
		x = rand()%2;
	print(a);	
	split(a);
	print(a);	
	return 0;
}
