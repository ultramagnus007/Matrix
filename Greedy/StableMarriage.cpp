#include <iostream>
#include <queue>
using namespace std;

const int N = 4;

vector<vector<int>> MEN{
        {3, 1, 2, 0},
        {1, 0, 2, 3},
        {0, 1, 2, 3},
        {0, 1, 2, 3}
		};

vector<vector<int>> WOMEN{
        {0, 1, 2, 3},
        {0, 1, 2, 3},
        {0, 1, 2, 3},
        {0, 1, 2, 3}
		};

int main()
{
	vector<int> M(N, -1);
	vector<int> W(N, -1);

	while(true)
	{
		bool finish = true;
		for(int i = 0; i < N; i++)
		{
			if(M[i] != -1)
				continue;
			finish = false;
			for(int j = 0; j < N; j++)
			{
				int w = MEN[i][j];
				if(W[w] == -1)
				{
					W[w]  = i;
					M[i] = w;
					break;
				}
				for(int k = 0; k < N; k++)
				{
					if(WOMEN[w][k] == W[w])
						break;
					if(WOMEN[w][k] == W[w])
					{
						M[W[w]] = -1;
						W[w]  = i;
						M[i] = w;
						break;
					}
				}
			}				
		}
		if(finish)
			break;
	}
	for(int i = 0; i < N; i++)
		cout<<i<<" "<<M[i]<<endl;
	return 0;
}
