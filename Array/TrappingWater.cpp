#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int TrapWater(const vector<int> &a)
{
	stack<int> S;
	int TW = 0;
	for(int i = 0; i < a.size(); i++)
	{
		if(a[i] == 0)
			continue;
		int pre = -1;
		while(!S.empty())
		{
			if(a[S.top()] >= a[i])
			{
				TW+= (i-S.top()-1)*a[i];
				break;
			}else
			{
				if(pre != -1)
					TW -= (pre - S.top()-1)*min(a[pre], a[S.top()]);
				pre = S.top();
				S.pop();
			}
		}
		S.push(i);
		if(pre != -1)
			TW+=(i-pre-1)*min(a[pre], a[i]);
			
		cout<<i<<" "<<pre<<" "<<TW<<endl;
	}
	return TW;
}

int main()
{
	vector<int> a1 = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
	cout<<"Maximum Water = "<<TrapWater(a1)<<endl;
	//vector<int> a2 = {3, 0, 0, 2, 0, 4};
	//cout<<"Maximum Water = "<<TrapWater(a2)<<endl;

	return 0;
}

#if 0
bool islocalMax(const vector<int> &a, int i)
{
	if(i == 0 || i  == a.size()-1)
		return a[i] != 0;
	return a[i] > a[i-1] && a[i] > a[i+1];
}

int TrapWater(const vector<int> &a)
{
	int N = a.size();
	int i = 0;
	while(i < N && islocalMax(a, i) == false)
		i++;
	int trapwater = 0;
	while(true)
	{
		int j = i+1;
		int sub = 0;
		while(j < N && islocalMax(a, j) == false)
		{
			sub+=a[j];
			j++;
		}
		if(j == N)
			break;
		trapwater += min(a[i], a[j]) *(j-i-1) - sub;
		i = j;
	}
	return trapwater;
}
#endif


