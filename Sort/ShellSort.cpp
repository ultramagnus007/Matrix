#include "Sort.h"

void ShellSort(vector<int> &a)
{
	vector<int> gaps{701, 301, 132, 57, 23, 10, 4, 1};
	for(const auto & g: gaps)
	{
		for(int i = 0; i+g < a.size(); i++)
		{
			for(int j = i+g; j-g >=0; j-=g)
			{
				if(a[j] < a[j-g])
					swap(a[j], a[j-g]);
				else
					break;				
			}
		}
	}
}



