// WAP TO FIND GREATEST AMONG 3 NUMBER USING IF ELSE

#include<stdio.h>
int main()
{
    int a,b,c;
    printf("Enter The Value Of A,B and C");
    scanf("%d %d %d",&a,&b,&c);
    if((a>b)&&(a>c))
    {
        printf("The Greatest Among in A,B and C is %d",a);
    }
    else if((b>a)&&(b>c))
    {
        printf("The Greatest Among in A,B and C is %d",b);
    }
    else
    {
        printf("The Greatest Among in A,B and C is %d",c);
    }
}