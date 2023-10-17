// UNARY OPERATOR i.e., ++,--

#include<stdio.h>
int main()
{
    int a=5;
    a++;                // POST INCEREMENT
    printf("%d",a);
    
    int b=5;
    ++b;                // PRE INCEREMENT
    printf("\n%d",b);  

    int c=6;
    --c;               // PRE DECREMENT
    printf("\n%d",c); 

    int d=6;
    d--;
    printf("\n%d",d);
}
