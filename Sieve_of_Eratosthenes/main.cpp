#include<bits/stdc++.h>
using namespace std;

// Sieve of Eratosthenes 
// Most efficient algorithm to find the prime number less than N 
// complexity: 0(nlog(logn))
int main()
{
    int count = 0, n;
    cin >> n;
    vector<bool> prime(n, true);
    prime[0] = prime[1] = false;

    for (int i = 2; i < 11; i++)
    {
        if(prime[i])
        {
            count++;
            for (int j = 2*i; j < 11; j = j + i )
            {
                prime[j] = 0;
            }
        }
    }
    for(int i: prime)
    {
        cout << i;
    }
}