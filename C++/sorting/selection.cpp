#include<bits/stdc++.h>
using namespace std;
int main()
{   //array size input and array input
    int n;
    cin>>n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin>>a[i];
    }
    //selection sort logic
    for (int i = 0; i < n-1; i++)
    {   int check=a[i];
        int index=i;
        for (int j = i+1; j < n; j++)
        {
            if(a[j]<check){
                check=a[j];
                index=j;
            }
        }
        int t=a[i];
        a[i]=a[index];
        a[index]=t;
    }
    //print
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    return 0;
}

