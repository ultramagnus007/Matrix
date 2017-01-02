#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include "Sort.h"
using namespace std;

bool isSorted(const vector<int> &a)
{
	for(int i = 0; i < a.size()-1; i++)
	{	
		if(a[i]  > a[i+1])
			return false;
	}
	return true;
}

int main()
{
	int T = 1000;
	bool issorted = true;
	srand(time(NULL));
	int R = 100;
	int N = 100;
	while(T-- >0)
	{
		vector<int> a(N);
		for(int i = 0; i < N; i++)
			a[i] = rand()%R;
		//BubbleSort(a);
		//InsertionSort(a);
		//SelectionSort(a);
		//MergeSort(a);
		//MergeAlternateSort(a);
		//QuickSort(a);
		//QuickSort3Way(a);
		//RadixSortLSD(a);
		//ShellSort(a);
		RadixSortMSD(a);
		issorted &= isSorted(a);
		if(!issorted)
			break;
	}
	if(issorted)
		cout<<"SORTED"<<endl;
	else
		cout<<"NOT SORTED"<<endl;
	return 0;
}
