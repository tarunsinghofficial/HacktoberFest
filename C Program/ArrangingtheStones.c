/*Rahul and Tina have collected a few stones. They are given an array and are asked to arrange the stones in an array according to their weights. Tina is given the first half of the array and she arranges weight of stones in increasing order and Rahul does the same task for his stones in 2nd half of the array.

Now we wants you to completely sort this array from start to end containing weight of stones placed.

Example
Input
2
6
2 3 8 -1 7 10
5
-4 6 9 -1 3

Output
-1 2 3 7 8 10 
-4 -1 3 6 9 */

#include <stdio.h>
 void swap( long long int *a, long long int *b){
     long long int temp;
     temp=*a;
     *a=*b;
     *b=temp;
}
long long int part(long long   int a[], int low,int high){
      long long int pivot=a[high];
       long long int k=low-1,l;
       for(l=low;l<=high-1;l++){
           if(a[l]<=pivot){
               k++;
               swap(&a[k],&a[l]);
           }
       }
       swap(&a[k+1],&a[high]);
       return k+1;
 }
void quick( long long int a[],int low,int high){
    if(low<high){
      long long int pi=part(a,low,high);
      
        quick(a,low,pi-1);
        quick(a,pi+1,high);
        
    }
}  
  int main()
  {
   int t;
   scanf("%d",&t);
   while(t--){
     long long int n,i;
     scanf("%lld",&n);
     long long int a[n];
     for(i=0;i<n;i++){
       scanf("%lld",&a[i]);
     }
     quick(a,0,n-1);
     for(i=0;i<n;i++){
       printf("%lld ",a[i]);
     }
     printf("\n");
   }
    return 0;
  }
