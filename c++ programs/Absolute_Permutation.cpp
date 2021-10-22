#include<bits/stdc++.h>
using namespace std;

int main()
{
    int no,n,k,temp,flag;
    cin >> no;
    while(no--)
    {
        cin >> n >> k;
        int arr[n];
        int ind[n] = {0};
        if(n%2 !=0  && k!=0)
        {
            cout << -1 << endl;
            continue;
        }
        if(!(n%2 == 0 && n%k==0))
        {
            cout << -1 << endl;
            continue;
        }
        for(int i =0 ;i<n;i++)
        {
            arr[i] = i+1;
        }
        if(k==0)
        {
            for(int i =0 ;i<n;i++)
            {
            cout <<  arr[i] << " ";
            }
        }
        


    }
}