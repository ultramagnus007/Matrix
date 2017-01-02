#include <iostream>
#include <vector>
using namespace std;

void print(vector<int> &S, int k)
{
	if(k == 0)
	{
		cout<<"{phi}"<<endl;
		return;
	}
	for(int i = 0; i <= k; i++)
		cout<<S[i]<<" ";
	cout<<endl;
}

void GenerateSubSets(const vector<int> &a, vector<int> &S, int i, int pos)
{
	if(i == a.size())
	{
		print(S, pos);
		return;
	}
	GenerateSubSets(a, S, i+1, pos);
	S[pos] = a[i]; 
	GenerateSubSets(a, S, i+1, pos+1);
}
int main()
{
	const int N = 5;
	vector<int> a(N);
	for(int i = 0; i < N; i++)
		a[i] = i+1;
	vector<int> S(N);
	GenerateSubSets(a, S, 0, 0);
	return 0;
}
