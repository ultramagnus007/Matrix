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
	int i = lo;
	while(i <= hi)
	{
		if(a[i] > pivot)
			swap(a[i], a[hi--]);
		else if(a[i] < pivot)
			swap(a[i++], a[lo++]);
		else
			i++;
	}
}
int main()
{
	const int N = 25;
	vector<int> a(N);
	srand(time(NULL));
	for(auto &x: a)
		x = rand()%3;
	print(a);	
	split(a);
	print(a);	
	return 0;
}
