/*
Interval partitioning.
 Lecture j starts at s j and finishes at f j .
 Goal: find minimum number of classrooms to schedule all lectures
 so that no two lectures occur at the same time in the same room.
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;


class CompareStart
{
	public:
	bool operator()(const pair<float, float> &p1, const pair<float, float> &p2)const
	{
		return p1.first < p2.first;
	}
};

class CompareEnd
{
	public:
	bool operator()(const float &p1, const float &p2)const
	{
		return p1 > p2;
	}
};

int main()
{
    //Given Start Time And Finish Time of Lectures
    const int N = 10;
    vector<pair<float, float>> S{ {9, 10.5}, {9, 12.5}, {9, 10.5},
						   {11, 12.5},{11, 14},  {13, 14.5},
						   {13, 14.5},{14, 16.5},{15, 16.5},
						   {15, 16.5}
					     };
	sort(S.begin(), S.end(), CompareStart());
	priority_queue<float, vector<float>, CompareEnd> pq;
	int rooms = 0;
	int minrooms = 0;
	for(const auto & p: S)
	{
		//while(!pq.empty() && pq.top().second <= p.second) // mistake
		while(!pq.empty() && pq.top()<= p.first)
		{
				rooms--;	
				pq.pop();
		}
		pq.push(p.second);
		rooms++;
		minrooms = max(minrooms, rooms);
	}
	cout<<"minimum number of classrooms = "<<minrooms<<endl;
	return 0;
}
