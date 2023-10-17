// WAP TO CHECK THE NUMBER IS EVEN OR ODD USING SWITCH CASE

#include<stdio.h>
int main()
{
    int a;
    printf("Enter Any Number");
    scanf("%d",&a);
    switch (a%2)
    {
    case 0: printf("The Number is EVEN");
        break;
    
    default: printf("The Number is ODD");
        break;
    }
    return 0;
}