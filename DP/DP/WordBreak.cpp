/*
Given an input string and a dictionary of words, find out if the input string can be segmented into a space-separated sequence of dictionary words. See following examples for more details.
This is a famous Google interview question, also being asked by many other companies now a days.

Consider the following dictionary 
{ i, like, sam, sung, samsung, mobile, ice, 
  cream, icecream, man, go, mango}

Input:  ilike
Output: Yes 
The string can be segmented as "i like".

Input:  ilikesamsung
Output: Yes
The string can be segmented as "i like samsung" or "i like sam sung".
*/

#include <iostream>
#include <vector>
#include <string>
#include <set>
using namespace std;

bool isSegmented(const set<string>&S, const string &str)
{
	int N = str.length();
	vector<vector<bool>> table(N);
	for(auto &v:table)
		v.resize(N, false);
	for(int gap = 0; gap < N; gap++)
	{
		for(int i = 0; i+gap < N; i++)
		{
			int lo = i;
			int hi = lo+gap;
			string s = str.substr(lo, hi-lo+1);
			if(S.find(s) != S.end())
			{
				table[lo][hi] = true;
				continue;
			}
			for(int k = lo; k < hi; k++)
			{
				if(table[lo][k] && table[k+1][hi])
				{
					table[lo][hi] = true;
					break;
				}		
			}
		}
	}
	return table[0][N-1];
}


int main()
{
	set<string> S;
        S.insert("i");
        S.insert("like");
        S.insert("sam");
        S.insert("sung");
        S.insert("samsung");
        S.insert("mobile");
        S.insert("ice");
        S.insert("cream");
        S.insert("icecream");
        S.insert("man");
        S.insert("go");
        S.insert("mango");

        string str("ilikesamsung");


        if(isSegmented(S, str))
                cout<<"Yes it can be Segmented\n";
        else
                cout<<"No it can not be Segmented\n";
        return 0;
}

