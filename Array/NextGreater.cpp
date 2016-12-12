#include <iostream>
#include <vector>
#include <string>
using namespace std;


void nextGreater(string &s)
{
	int N = s.length();

	int viop = N-1;
	while(viop > 0 && s[viop-1] >= s[viop])
			viop--;	
	if(viop == 0)
	{
//		cout<<"No Greater Number\n"<<endl;
		return;
	}
	viop--;
	int justg = viop+1;
	while(justg < N && s[justg] > s[viop])
			justg++;
	justg--;
	swap(s[viop], s[justg]);
	int i = viop+1;
	int j = N-1;
	while(i < j)
	{
		swap(s[i], s[j]);
		i++;
		j--;
	}
}

int main()
{
    vector<string> a = {"256998776631", "534976", "4321", "1234", "218765", "25698731"};
	for(auto &s : a)
	{
	    nextGreater(s);
	    cout<<s<<endl;
	}
    return 0;
}

