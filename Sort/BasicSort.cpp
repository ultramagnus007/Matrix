#include <iostream>
#include <vector>
#include "Sort.h"
using namespace std;

void BubbleSort(vector<int> &a)
{
	int N = a.size();
	for(int i = 1; i < N; i++)
	{
		for(int j = 0; j < N-i; j++)
		{
			if(a[j] > a[j+1])
				swap(a[j], a[j+1]);
		}	
	}
}

void InsertionSort(vector<int> &a)
{
	int N = a.size();
	for(int i = 1; i < N; i++)
	{
		for(int j = i; j > 0; j--)
		{
			if(a[j] < a[j-1])
				swap(a[j], a[j-1]);
			else
				break;
		}
	}
}

void SelectionSort(vector<int> &a)
{
	int N = a.size();
	for(int i = N-1; i >0; i--)
	{
		int maxIndex = i-1;
		for(int j = 0; j < i; j++)
		{
			if(a[j] > a[maxIndex])
				maxIndex = j;
		}
		if(a[i] < a[maxIndex])
			swap(a[i], a[maxIndex]);
	}
}

