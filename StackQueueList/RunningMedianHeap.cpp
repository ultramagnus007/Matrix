#include <iostream>
#include <queue>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;


void insertionSort(vector<int> &a)
{
	for(int i = a.size()-1; i > 0; i--)
	{
		if(a[i] < a[i-1])
			swap(a[i], a[i-1]);
		else
			break;
	}
}

float getMedian(const vector<int> &a)
{
	int N = a.size();
	if(N==0)
		return 0;
	if(N%2 == 1)
		return a[N/2];
	else
		return a[N/2]/2.0+a[N/2-1]/2.0;
}

int main()
{
	priority_queue<int, vector<int>, less<int>> pqMax;
	priority_queue<int, vector<int>, greater<int>> pqMin;
	vector<int> a;
	int N = 1000;
	while(N-- > 0)
	{
		int x = rand()%100;
		a.push_back(x);
		insertionSort(a);
		if(pqMax.size() == pqMin.size())
		{
			if(pqMax.size() == 0 || x < pqMax.top())
				pqMax.push(x);
			else
				pqMin.push(x);
		}
		else if(pqMax.size() < pqMin.size())
		{
			if(x > pqMin.top())
			{
				pqMax.push(pqMin.top());
				pqMin.pop();
				pqMin.push(x);
			}else
				pqMax.push(x);
		}else
		{
			if(x < pqMax.top())
			{
				pqMin.push(pqMax.top());
				pqMax.pop();
				pqMax.push(x);
			}
			else
				pqMin.push(x);
		}
			
		float median = 0;
		if(a.size()%2 == 1) 
			median = (pqMin.size() > pqMax.size())? pqMin.top(): pqMax.top();
		else
			median = pqMin.top()/2.0+pqMax.top()/2.0;
		if(median != getMedian(a))
		{
			cout<<median<<" "<<getMedian(a)<<" "<<a.size()<<" "<<pqMax.size()<<" "<<pqMin.size()<<endl;
			cout<<"Bad"<<endl;
			return 0;
		}
	}
	cout<<"Good"<<endl;
	return 0;
}
