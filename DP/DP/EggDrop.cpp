/*
The following is a description of the instance of this famous puzzle involving k=2 eggs and a building with n=36 floors.

Suppose that we wish to know which stories in a 36-story building are safe to drop eggs from, and which will cause the eggs to break on landing. We make a few assumptions:

…..An egg that survives a fall can be used again.
…..A broken egg must be discarded.
…..The effect of a fall is the same for all eggs.
…..If an egg breaks when dropped, then it would break if dropped from a higher floor.
…..If an egg survives a fall then it would survive a shorter fall.
…..It is not ruled out that the first-floor windows break eggs, nor is it ruled out that the 36th-floor do not cause an egg to break.

If only one egg is available and we wish to be sure of obtaining the right result, the experiment can be carried out in only one way. Drop the egg from the first-floor window; if it survives, drop it from the second floor window. Continue upward until it breaks. In the worst case, this method may require 36 droppings. Suppose 2 eggs are available. What is the least number of egg-droppings that is guaranteed to work in all cases?
The problem is not actually to find the critical floor, but merely to decide floors from which eggs should be dropped so that total number of trials are minimized.
*/

#include <iostream>
#include <vector>
using namespace std;


int MinEggDrop(int E, int F)
{
	vector<vector<int>> table(E+1);
	for(auto &v: table)
		v.resize(F+1, 0);
	for(int i = 1; i <= E; i++)
	{
		for(int j = 1; j <= F; j++)
		{
			table[i][j] = j;
			if(i==1)continue;
			for(int k = 1; k < j; k++)	
			table[i][j] = min(table[i][j], 1+max(table[i-1][k-1], table[i][j-k]));
		}
	}
	return table[E][F];
}

int main()
{
        int E = 2;
        int F = 36;
        cout<<MinEggDrop(E, F)<<endl;
        return 0;
}

