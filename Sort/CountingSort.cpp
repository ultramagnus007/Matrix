#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

#if 0
void CountingSort(char *a)
{
	const int R = 26;
	vector<int> count(R, 0);
	for(int i = 0; a[i] != '\0'; i++)
		count[a[i] - 'a']++;
	for(int i = 0, k = 0; i < R; i++)
	{
		while(count[i]-- > 0)
			a[k++] = (char)(i+'a');
	}
}
#endif

void CountingSort(char *a)
{
	const int R = 26;
	vector<int> count(R, 0);
	int i = 0;
	for(; a[i] != '\0'; i++)
		count[a[i] - 'a']++;
	int N = i;
	for(int i = 1; i < R; i++)
		count[i] += count[i-1];
	char * b = new char[N];
	for(int i = N-1; i >= 0; i--)
	{
		//b[count[a[i]-'a']--] = a[i]; /*Mistake*/
		b[count[a[i]-'a']-- -1] = a[i];
	}
	for(int i = 0; i < N; i++)
		a[i] = b[i];
	delete [] b;
}

int main()
{
	char a[] = "aasdefwprjiuvsjficsdifhiseoijfsonhaohduahidiuweiwefiuhwefiu";
	cout<<a<<endl;
	CountingSort(a);
	cout<<a<<endl;
	return 0;
}
