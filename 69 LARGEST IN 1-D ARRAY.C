// WAP TO PRINT THE LARGEST NUMBER AMONG 1-D ARRAY

#include<stdio.h>
int main(){
    int a[20],n,i,max;
    printf("Enter Size Of Array");
    scanf("%d",&n);
    printf("Enter Elements");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    max=a[0];
    for(i=0;i<n;i++)
    if(a[i]>max)
    {
        max=a[i];
    }
    printf("Largest Number Is %d",max);

}