/*
Suppose there is a circle. There are petrol pumps on that circle. Petrol pumps are numbered to (both inclusive). You have two pieces of information corresponding to each of the petrol pump: (1) the amount of petrol that particular petrol pump will give, and (2) the distance from that petrol pump to the next petrol pump.

Initially, you have a tank of infinite capacity carrying no petrol. You can start the tour at any of the petrol pumps. Calculate the first point from where the truck will be able to complete the circle. Consider that the truck will stop at each of the petrol pumps. The truck will move one kilometer for each litre of the petrol.

Input Format

The first line will contain the value of .
The next lines will contain a pair of integers each, i.e. the amount of petrol that petrol pump will give and the distance between that petrol pump and the next petrol pump.

Constraints:

Output Format

An integer which will be the smallest index of the petrol pump from which we can start the tour.
*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() 
{
    int N;
    cin>>N;
    vector<int> a(N);
    for(auto &x: a)
    {
        int petrol, distance;
        cin>>petrol>>distance;
        x = petrol - distance;
    }
    long long S = 0;
    int i = 0, j = 0;
    int size = 0;
    while(i < N)
    {
        S+=a[j++];
        size++;
        while(S < 0)
        {
            S-=a[i++];
            size--;
        }
        j=j%N;
        if(size==N && S >= 0)
            break;
    }
    cout<<i<<endl;
    return 0;
}
