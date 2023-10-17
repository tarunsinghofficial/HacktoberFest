// WAP TO DESIGN A CALCULATOR USING IF ELSE LADDER

#include<stdio.h>
int main()
{
    int a,b;
    char ch;
    printf("Enter The Value Of A and B ");
    scanf("%d %d",&a,&b);
    printf("Enter Operation To Be Performed +,-,*,/:");
    scanf(" %c",&ch);
    if(ch=='+')
    {
        printf("The Sum Of A and B is %d",(a+b));
    }
    else if(ch=='-')
    {
        printf("The Difference Of A and B is %d",(a-b));
    }
    else if(ch=='*')
    {
        printf("The Product Of A and B is %d",(a*b));
    }
    else if(ch=='/')
    {
        printf("The Division Of A and B is %d",(a/b));
    }
    else
    {
        printf("Invalid Choice");
    }
    return 0;
}