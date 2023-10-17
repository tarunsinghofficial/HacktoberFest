// WAP TO SHOW THE WORKING OF ASSIGNMENT OPERATOR i.e.,=,+=,-=,*=,%=

#include<stdio.h>
int main()
{
    int a=8; // assigning value of a equal to 8 by = operator
    
    printf("Value Of A is %d",a);

    a += 12; // assigning to a by adding 12
    
    printf("\nValue Of A is %d",a);

    a-=4;   // assigning to a by subtracting 4

    printf("\nValue Of A is %d",a);

    a *= 2;  // assigning to a by multiplying with 2

    printf("\nValue Of A is %d",a);

    a %= 8;  // assigning to a by diving it by 8

    printf("\nValue Of A is %d",a);

    return 0;
}