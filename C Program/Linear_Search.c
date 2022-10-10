#include<stdio.h>
void input(int a[],int n)
{   int i;
    printf("Enter array elements :\n");
	for(i=0;i<n;i++)
	scanf("%d",a+i);
}
int search(int a[],int n,int num)
{
	int i;
	for(i=0;i<n;i++)
	{
		if(num==a[i])
		return i;
	}
	return -1;
}
int main()
{   int n,i,num;
	printf("Enter size of array :\n");
	scanf("%d",&n); int a[n];
	input(a,n);
	printf("Enter element to search :\n");
	scanf("%d",&num);
	int f=search(a,n,num);
	if(f!=-1)
	printf("Found at index : %d",f);
	else printf("Element not found \n");
	return 0;
}
