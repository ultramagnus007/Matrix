#include <iostream>
using namespace std;

void RemoveDuplicate(char *a)
{
	int i = 0;
	int j = 0;
	while(a[j] != '\0')
	{
		while(a[j] == a[i])
			j++;
		a[++i] = a[j];
	}
}

int main()
{
    char a[] = "AAAAAABBBBBBCCCCCCCCCCDEF";
    cout<<a<<endl;
    RemoveDuplicate(a);
    cout<<a<<endl;
    return 0;
}
