/*
Minimizing lateness problem.
・ Single resource processes one job at a time.
・ Job j requires t j units of processing time and is due at time d j .
・ If j starts at time s j , it finishes at time f j = s j + t j .
・ Lateness: l j = max { 0, f j – d j }.
・ Goal: schedule all jobs to minimize maximum lateness L = max j l j .
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

class Compare
{
	public:
	bool operator()(const pair<int, int> &p1, const pair<int, int> &p2) const
	{
		return p1.second < p2.second;
	}
};

int main()
{
	//processing time and due time pair
    vector<pair<int,int>> a = { {3,6}, {2,8}, {1,9}, {4,9}, {3,14}, {2,15}};
	sort(a.begin(), a.end(), Compare());

	int ST = 0;
	int maxlate = 0;
	for(const auto &p:a)
	{
		maxlate = max(maxlate, ST+p.first-p.second);
		cout<<ST<<","<<ST+p.first<<endl;
		ST += p.first;
	}
	if(maxlate < 0)
		maxlate = 0;
	cout<<"Maximum Lateness = "<<maxlate<<endl;
	return 0;
}
