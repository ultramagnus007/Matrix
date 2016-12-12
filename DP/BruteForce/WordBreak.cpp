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
#include <set>
using namespace std;


bool isSegmented(const set<string> &S, const string &a, int lo, int hi)
{
	if(lo > hi)
		return true;
	if(S.find(a.substr(lo, hi-lo+1)) != S.end())	
		return true;
	for(int i = lo; i < hi; i++)
		if(isSegmented(S, a, lo, i) && isSegmented(S, a, i+1, hi))
			return true;
	return false;
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
	string a("ilikesamsung");
	if(isSegmented(S, a, 0, a.length()-1))
		cout<<"YES"<<endl;
	else
		cout<<"NO"<<endl;
	return 0;
}
