#include <bits/stdc++.h>
using namespace std;

int Binary_Search(int arr[], int n,int x)
{
    int s = 0;
    int e = n-1;
    while(s<=e)
    {
        int mid = (s+e)/2;
        if(arr[mid]==x) return mid;
        else if(arr[mid]>x) e = mid-1;
        else if(arr[mid]<x) s = mid+1;
    }
    return -1;
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for(int i=0; i<n; ++i) cin >> arr[i];
    sort(arr, arr+n);
    int x; cin >> x;
    int res = Binary_Search(arr, n, x);
    if(res==-1) cout << "Element is not found";
    else cout << "Element found at " << res+1 << " position";
    return 0;
}