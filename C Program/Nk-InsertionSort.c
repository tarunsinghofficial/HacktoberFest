// PROGRAM-NAME : Insertion Sort
// By Nisha
// PROGRAM-CODE :
#include <math.h>

#include <stdio.h>

int main()

{

    int a[50],n,i,key,j;

    printf ("how many elements ");

    scanf("%d",&n);

    printf("enter the elements to sort");

    for(int i=0;i<n;i++)

    scanf("%d",&a[i]);

for(i=1;i<n;i++)

{

key=a[i];

j=i-1;

while(j>=0 && a[j]>key)

{

a[j+1]=a[j];

j = j - 1;

}

a[j + 1] = key;

}

printf("the sorted array:\n");

for (i=0;i<n;i++)

printf("%d",a[i]);

return 0;

}
