#include<stdio.h>
void input(int a[],int n)
{   int i;
    printf("Enter array elements :\n");
	for(i=0;i<n;i++)
	scanf("%d",a+i);
}
void display(int a[],int n)
{   int i;
	for(i=0;i<n;i++)
	printf("%d  ",a[i]);
 printf("\n");
}
void sort(int a[],int n)
{  int i,j;
   for(i=0;i<n;i++)
   {
   	 for(j=i+1;j<n;j++)
   	 {
   	 	if(a[i]>a[j])
   	 	 { 
   	 	    int t=a[i]; a[i]=a[j]; a[j]=t;
			 }
		}
   }
}
int main()
{
	int n,i;
	printf("Enter size of array :\n");
	scanf("%d",&n); 
	int a[n];
	printf("Enter array elements : \n");
	input(a,n);
	printf("Enter array elements : \n");
	display(a,n);
	sort(a,n);
	printf("Sorted array : \n");
	display(a,n);
	return 0;
}
