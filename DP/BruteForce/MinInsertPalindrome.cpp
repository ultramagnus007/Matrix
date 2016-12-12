#include <iostream>
#include <cstring>
using namespace std;


int MinInsert(char * a, int lo, int hi)
{
	if(lo >= hi)
		return 0;
	if(a[lo] == a[hi])
		return MinInsert(a, lo+1, hi-1);
	else
		return 1+min(MinInsert(a, lo+1, hi), MinInsert(a, lo, hi-1));
}

int main()
{
        char a[] = "geeks";
	cout<<MinInsert(a, 0, strlen(a)-1)<<endl;	
	return 0;
}
