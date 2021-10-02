#include <bits/stdc++.h>
using namespace std;
void simpleSieve(int limit, vector<int> &prime)
{
    vector<bool> mark(limit+1, true);
    for(int p=2;(p*p)<limit;p++)
    {
        if(mark[p]==true)
        {
            for(int i=(p*p);i<limit;i+=p)
            {
                mark[i] = false;
            }
        }
    }
    for(int p=2;p<limit;p++)
    {
        if(mark[p]==true)
        {
            prime.push_back(p);
            cout << p << " ";
        }
    }
}
void segmentedSieve(int n)
{
    int limit = floor(sqrt(n))+1;
    vector<int> prime;
    prime.reserve(limit);
    simpleSieve(limit,prime);
    int low = limit;
    int high = 2*limit;
    while(low<n)
    {
        if(high>=n)
        {
            high = n;
        }
        bool mark[limit+1];
        memset(mark, true, sizeof(mark));
        for(int i=0;i<prime.size();i++)
        {
            int loLim = floor(low/prime[i])*prime[i];
            if(loLim<low)
            {
                loLim += prime[i];
            }
            for(int j=loLim;j<high;j+=prime[i])
            {
                mark[j-low] = false;
            }
        }
        for(int i=low;i<high;i++)
        {
            if(mark[i-low]==true)
            {
                cout << i << " ";
            }
        }
        low = low + limit;
        high = high + limit;
    }
}
int main ()
{
    int n;
    cin >> n;
    segmentedSieve(n);
    return 0 ;
}
