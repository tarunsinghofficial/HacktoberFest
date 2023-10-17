// WAP TO CHECK THE NUMBER IS POSITIVE OR NEGATIVE

#include<stdio.h>
int main()
{
    int n;
    printf("Enter the Number");
    scanf("%d",&n);
    switch(n>0)
    {
        case 1: printf("The Number Is Positive");
        break;
        case 0: if(n<0)
                printf("The Number is Negative");
                else
                printf("The Number is Zero");
        

    }
}