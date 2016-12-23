#include <iostream>
#include <stack>

using namespace std;

void Compress(char *a)
{
	int i = 0, j = 0;
	while(a[j] != '\0')
	{
		int count = 0;
		while(a[j] != '\0' && a[i] == a[j])
		{
			count++;
			j++;
		}
		if(count > 1)
		{
			stack<int> S;
			while(count > 0)
			{
				S.push(count%10);
				count/=10;
			}
			while(!S.empty())
			{
				a[++i] = (char)(S.top()+'0');
				S.pop();
			}
		}
		a[++i] =  a[j];
	}
}

void Decompress(char * a)
{
	int n = 0;
	int i = 0;
	while(a[i] != '\0')
	{
		if(isalpha(a[i]))
		{
			n++;
			i++;
			continue;
		}
		int count = 0;
		while(isdigit(a[i]))
		{
			count = 10*count+(a[i] - '0');
			i++;
		}	
		if(count > 0)
			n+=count-1;
	}
	int j = n;
	a[j] = '\0';
	i--, j--;
	while(i>=0)
	{
		stack<int> S;
		while(isdigit(a[i]))
		{
			S.push(a[i]-'0');
			i--;
		}
		int count = S.empty()?1:0;
		while(!S.empty())
		{
			count = 10*count+S.top();
			S.pop();
		}
		while(count-- != 0)
			a[j--] = a[i];
		i--;
	}
}
int main()
{
    char a[] = "AAAAAAAAAAAAAAAAAAAAAABBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBCDDDEGGHHHH";
    cout<<a<<endl;
    Compress(a);
    cout<<a<<endl;
    Decompress(a);
    cout<<a<<endl;
    return 0;
}

