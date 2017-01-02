#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;


class CompareFinish
{
	public:
	bool operator()(const pair<int, int> &p1, const pair<int, int> &p2) const
	{
		return p1.second < p2.second;
	}
};

int main()
{
	//start time and finish time pair
	vector<pair<int,int>>  a{{1,2}, {3,4}, {0,6}, {5,7}, {8,9}, {5,9}};
	sort(a.begin(), a.end(), CompareFinish());
	int ET = 0;
	int numtasks = 0;
	for(const auto &p: a)
	{
		if(ET <= p.first)
		{
			cout<<p.first<<" ";
			numtasks++;
			ET = p.second;
		}
	}
	cout<<endl;
}
