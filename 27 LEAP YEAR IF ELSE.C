// WAP TO CHECK THE ENTERED YEAR IS LEAP OR NOT USING IF ELSE

#include<stdio.h>
int main()
{
    int a;
    printf("Enter A Year");
    scanf("%d",&a);
    if(a%4==0)
    {
        printf("Entered year is leap");
    }
    else if(a%400==0)
    {
        printf("Entered year is leap");
    }
    else
    {
        printf("Entered year is not a leap");
    }
}