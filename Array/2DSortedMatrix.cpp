

#include <iostream>
#include <vector>
using namespace std;


void search(vector<vector<int>> &a, int key)
{
	int N = a.size();
	int M = a[0].size();
	int i = 0, j = M-1;
	while(i < N && j >= 0)
	{
		if(a[i][j] == key)
		{
			cout<<i<<","<<j<<endl;
			return;
		}
		else if(key > a[i][j])
			i++;
		else
			j--;
	}	
}

void QuadPartition(vector<vector<int>> &a, int key, int top , int bottom, int left , int right)
{
	if(top > bottom || left > right)
		return;

	int x = (top+bottom)/2;
	int y = (left+right)/2;
	if(a[x][y] == key)
	{
		cout<<x<<","<<y<<endl;
		return;
	}
	if(key > a[x][y])
	{
        QuadPartition(a, key, top, x, y+1, right);
        QuadPartition(a, key, x+1, bottom, y, right);
        QuadPartition(a, key, x+1, bottom, left, y-1);
	}
	else
	{
        QuadPartition(a, key, top, x-1, y, right);
        QuadPartition(a, key, top, x, left, y-1);
        QuadPartition(a, key, x+1, bottom, left, y-1);
	}
}


int bsearch(vector<vector<int>> &a, int key, int top, int bottom, int col)
{
	int mid = -1;
	while(top <= bottom)
	{
		mid = (top+bottom)/2;
		if(a[mid][col] == key)
			return mid;
		else if(key > a[mid][col])
			top = mid+1;
		else
			bottom = mid-1;
	}
	return mid;
}


void BinaryPartition(vector<vector<int>> &a, int key, int top, int bottom, int left, int right)
{	
	if(top > bottom || left > right)
		return;
	int col = (left+right)/2;
	int row = bsearch(a, key, top, bottom, col);
	if(row == -1)
		return;
	if(a[row][col] == key)
	{
		cout<<row<<","<<col<<endl;
		return;
	}
	BinaryPartition(a, key, top, row-1, col+1, right);
	BinaryPartition(a, key, row+1, bottom, left, col-1);
}

int main()
{
	const int N = 4;
	const int M = 4;

	vector<vector<int>> a = 
				{
		          {10, 20, 30, 40},
                  {15, 25, 35, 45},
                  {27, 29, 37, 48},
                  {32, 33, 39, 50},
                };
	

    for(int i = 0 ; i < N; i++)
    for(int j = 0; j < M; j++)
		BinaryPartition(a, a[i][j], 0, 0, N-1, M-1);

	//search(a, a[i][j]);
    //QuadPartition(a, a[i][j], 0 , N-1, 0 , M-1);

  return 0;
}
