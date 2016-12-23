#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
using namespace std;


void print(vector<int> &a)
{
	for(auto x:a)
		cout<<x<<" ";
	cout<<endl;
}

void shuffle(vector<int> &a)
{
	srand(time(NULL));
	int N = a.size();
	for(int i = 0; i < N; i++)
	{
		int k = rand()%(i+1);
		swap(a[i], a[k]);
	}
}

int main()
{

    vector<int> a = {84, 67, 25, 47, 39, 78, 57, 13, 56, 68};
    print(a);
    shuffle(a);
    print(a);
    return 0;
}

