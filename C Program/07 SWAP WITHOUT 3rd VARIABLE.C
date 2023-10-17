// SWAP OF TWO NUMBER WITHOUT USING 3rd VARIABLE

#include<stdio.h>
int main()
{
    int a,b;
    printf("Enter The value of A and B");
    scanf("%d %d",&a,&b);
    printf("\nvalue before Swapping A is %d and B is %d",a,b);
    a=a+b;
    b=a-b;
    a=a-b;
    printf("\nvalue after Swapping A is %d and B is %d ",a,b);
    return 0;
}