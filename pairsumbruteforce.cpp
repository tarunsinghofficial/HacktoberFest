#include <bits/stdc++.h>
#include<climits>
using namespace std;
bool pairsum(int arr[],int n,int k){
    for (int i = 0; i < n-1; i++)
    {
        for (int j = i+1; j < n; j++)
        {
            if(arr[i]+arr[j]==k){
                cout<<i<<" "<<j<<endl;
                return true;
            }
            
        }
    }
    return false;
}
int main()
{
    int n;
    cin >> n;
    
    int arr[n];
    

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int k;
    cin>>k;
    cout<<pairsum(arr,n,k);
    return 0;
}