// WAP TO CHECK THE ENTERED YEAR IS LEAP OR NOT USING TERNARY OPERATOR

#include<stdio.h>
int main()
{
    int n;
    printf("Enter a year");
    scanf("%d",&n);
    (n%4==0)?(n%400==0)?(n%100==0):(printf(" %d is Leap Year",n)):((printf("%d is Not a Leap Year",n)));
    return 0;
    
}