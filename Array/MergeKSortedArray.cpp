#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Compare
{
	private:
	vector<vector<int>> *a;	
	public:
	Compare(vector<vector<int> > *a){this->a = a;}
	bool operator()(const pair<int, int>&p1, const pair<int, int>&p2) const
	{
		return (*a)[p1.first][p1.second] > (*a)[p2.first][p2.second];
	}

};

int main()
{
	const int N = 3;
	const int M = 4;
	vector<vector<int> > a =
				{{2, 6, 12, 34},
                {1, 9, 20, 1000},
                {23, 34, 90, 2000}};

	Compare comp(&a);
	priority_queue<pair<int,int> , vector<pair<int,int>>, Compare> Q(comp);
	
	for(int i = 0; i < N; i++)
		Q.push(pair<int, int>(i, 0));
	while(!Q.empty())
	{
		pair<int, int> p = Q.top();
		Q.pop();
		cout<<a[p.first][p.second]<<" ";
		if(p.second+1 < a[p.first].size())
			Q.push(pair<int, int>(p.first, p.second+1));		
	}
	cout<<endl;	
	return 0;
}
