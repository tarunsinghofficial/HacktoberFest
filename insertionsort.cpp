#include<bits/stdc++.h>

using namespace std;

int main()
{
    //insertion sort
    int a[5] = {1,56,94,12,31};
    //if(n>1)
 int i,j;
 for(i=0;i<5-1;i++)
 {
     for(j=i+1;j>0;j--)
     {
         if(a[j]>=a[j-1])
         {
             break;
         }
         swap(a[j],a[j-1]);
     }
 }
 for(i=0;i<5;i++)
 {
     cout<<a[i]<<" ";
 }
 return 0;
}
