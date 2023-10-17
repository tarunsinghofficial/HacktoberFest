// WAP TO CHECK THE GIVEN NUMBER IS EVEN OR ODD USING IF ELSE 

#include<stdio.h>
int main()
{
    int n;
    printf("Enter Any Number");
    scanf("%d",&n);
    if(n%2==0)
    {
        printf("Given Number is EVEN"); // if above condition is true then EVEN 
    }
    else
    {
        printf("Given Number is ODD"); // if abovr condition is false then ODD
    }
    return 0;
}