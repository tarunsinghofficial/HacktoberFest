// SWAPPING OF TWO NUMBER USING 3rd VARIABLE

#include<stdio.h>
int main()
{
    int a,b,temp;
    printf("Enter Value Of A and B");
    scanf("%d %d",&a,&b);
    printf("\nValue Before Swapping A is %d and B is %d",a,b);
    temp=a;
    a=b;
    b=temp;
    printf("\nValue After Swapping A is %d and B is %d",a,b);
    return 0;
}