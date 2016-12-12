/*
Given a string, find the length of the longest substring without repeating characters. For example, the longest substrings without repeating characters for “ABDEFGABEF” are “BDEFGA” and “DEFGAB”, with length 6. For “BBBB” the longest substring is “B”, with length 1. For “GEEKSFORGEEKS”, there are two longest substrings with length 7. 
*/
#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int LRSUBSTR(const char *a)
{
	int N = strlen(a);
	int si = 0;
	int se = 0;
	const int R = 26;
	vector<bool> exists(R, false);
	int i = 0, j = 0;
	int maxlen = 0;
	while(j < N)
	{
		while(exists[a[j]-'A'])
		{
			if(exists[a[i] - 'A'])
				exists[a[i] - 'A'] = false;
			i++;
		}
		if(j-i+1 > maxlen)
		{
			si = i;
			se = j;	
			maxlen = j-i+1;
		}
		exists[a[j]-'A'] = true;
		j++;
	}

	for(int i = si; i <= se; i++)
		cout<<a[i];
	cout<<endl;
	return se-si+1;
}

int main()
{
        char s1[] = "BBBBB";
        char s2[] = "ABDEFGABEF";
        char s3[] = "GEEKSFORGEEKS";
        cout<<LRSUBSTR(s1)<<endl;
        cout<<LRSUBSTR(s2)<<endl;
        cout<<LRSUBSTR(s3)<<endl;
        return 0;
}

