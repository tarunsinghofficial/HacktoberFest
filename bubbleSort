#include <bits/stdc++.h>
using namespace std;
void bubbleSort(int arr[], int n){
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-1-i;j++){
            if(arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]);
            }
        }
    }
}
int main()
{
    int a[]={3,2,5,6,4};
    int m=sizeof(a)/sizeof(a[0]);
    bubbleSort(a, m);
    for(int i=0;i<m;i++){
        cout<<a[i]<<" ";
    }
}
