#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int MaxSum(vector<vector<int>> &a)
{
	if(a.size()==0)
		return 0;
	int R = a.size();
	int C = a[0].size();
	

}

int main()
{
	vector<vector<int>> a = 
				  {{ 1,  2, -1, -4, -20},
		           {-8, -3,  4,  2,   1},
			       { 3,  8, 10,  1,   3},
				   {-4, -1,  1,  7,  -6}
				  };
	cout<<MaxSum(a)<<endl;
	return 0;
}
