// WAP TO DESIGN A CALCULATOR USING SWITCH CASE

#include<stdio.h>
int main()
{
    int a,b;
    char c;
    printf("Enter Any Two Number");
    scanf("%d %d",&a,&b);
    printf("Enter Operation to be Perform +,-,*,/:");
    scanf(" %c",&c);
    switch(c)
    {
        case '+': printf("Sum of A and B is %d",(a+b));
        break;
        case '-': printf("Difference Of A and B is %d",(a-b));
        break;
        case '*': printf("Product of A and B is %d",(a*b));
        break;
        case '/': printf("Division Of A and B is %d",(a/b));
        break;
        default: printf("Invalid Choice");
        break;
    }
}