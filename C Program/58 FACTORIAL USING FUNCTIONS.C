// WAP TO FIND FACTORIAL USING FUNCTION

#include<stdio.h>
int fact(int a);
int main()
{
    int a,f;
    printf("Enter value");
    scanf("%d",&a);
    f=fact(a);
    printf("Factorial is %d",f);
}
int fact(int a)
{
    int i,F=1;
    for(i=1;i<=a;i++)
    {
        F=F*i;
    }
    return F;
}