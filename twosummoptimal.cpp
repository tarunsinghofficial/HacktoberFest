#include<bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
    int n=6;
    int arr[n]={1,4,2344,2,30,3};
    int k=34;
    int i=0,j=n-1;
    sort(arr,arr+n);
   while (i<n&&j>=0)
   {
    /* code */
    if(arr[i]+arr[j]==k){
        cout<<i<<" "<<j;
        break;
    }
    if(arr[i]+arr[j]>k){
        j--;
    }
    if(arr[i]+arr[j]<k){
        i++;
    }
   }
   
    
    
    
    return 0;
}
