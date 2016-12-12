//Sliding Window minimum


#include <iostream>
#include <vector>
#include <climits>
#include <queue>
using namespace std;

void BruteForce(const vector<int> &a, int w)
{
	int N = a.size();
	for(int i = 0; i < N-w+1; i++)
	{
		int Min = INT_MAX;
		for(int j = i; j < i+w; j++)
			Min = min(Min, a[j]);
		cout<<Min<<" ";
	}
	cout<<endl;
}

void Optimized(const vector<int> &a, int w)
{
	int N = a.size();
	if(N==0)
		return;
	deque<int> Q;
	Q.push_back(0);
	for(int i = 1; i < w-1; i++)
	{
		if(a[Q.front()] >= a[i])
		{
			Q.pop_front();
			Q.push_back(i);
		}
	}
	for(int i = w-1; i < N; i++)
	{
		if(i-Q.front() >= w)
			Q.pop_front();	
		while(!Q.empty() && a[Q.back()] >= a[i])
			Q.pop_back();
		Q.push_back(i);
		cout<<a[Q.front()]<<" ";
	}
	cout<<endl;
}

int main()
{
    const int N = 50;
    int w = 5;
    vector<int> a(N);

	for(auto &x:a)
    {
        x = rand()%N +1;
        cout<<x<<" ";
    }
    cout<<endl;
    BruteForce(a, w);
    Optimized(a, w);
    return 0;
}
