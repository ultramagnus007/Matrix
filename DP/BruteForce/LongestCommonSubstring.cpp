#include <iostream>
#include <cstring>
using namespace std;


void LCSUB(char *a, char *b)
{
	int N1 = strlen(a);
	int N2 = strlen(b);
	int s = -1;
	int e = -1;
	int maxlen = 0;
	for(int i = 0; i < N1; i++)
	{
		for(int j = 0; j < N2; j++)
		{
			int p = i, q = j;
			int len = 0;
			while(p < N1 && q < N2)
			{
				if(a[p] == b[q])				
					len++;				
				else
					break;
				p++,q++;
			}
			if(len > maxlen)
			{
				s = i;
				e = p;
				maxlen = len;
			}
		}

	}
	if(maxlen > 0)
	{
		for(int i = s; i < e ;i++)
			cout<<a[i];
		cout<<endl;
	}else
		cout<<"NO CHARACTER COMMON"<<endl;
}

int main()
{
        char a[] = "OldSite:GeeksforGeeks.org";
        char b[] = "NewSite:GeeksQuiz.com";
        LCSUB(a, b);
        return 0;
}

