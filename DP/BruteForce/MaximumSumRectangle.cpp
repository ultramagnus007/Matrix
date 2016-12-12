#include <iostream>
#include <climits>
using namespace std;


const int R = 4;
const int C = 5;

int a[R][C] = {
                { 1,  2, -1, -4, -20},
                {-8, -3,  4,  2,   1},
                { 3,  8, 10,  1,   3},
                {-4, -1,  1,  7,  -6}
              };


int calsum(int top, int bottom, int left, int right)
{
	int sum = 0;
	for(int i  = top; i <= bottom; i++)
	{
		for(int j = left; j <= right; j++)		
			sum+=a[i][j];		
	}
	return sum;
}

int MaxSum()
{
	int maxsum = INT_MIN;
	for(int bottom = 0; bottom < R; bottom++)
	{
		for(int top = 0; top <= bottom; top++)
		{
			for(int right = 0; right < C; right++ )
			{
				for(int left = 0; left <= right; left++)
					maxsum = max(maxsum, calsum(top, bottom, left, right));
			}
		}
	}
	return maxsum;
}

int main()
{
	cout<<MaxSum()<<endl;
	return 0;
}
