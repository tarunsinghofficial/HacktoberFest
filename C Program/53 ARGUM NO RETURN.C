// WAP TO PRINT ADDITION OF TWO NUMBER (ARGUMENT,NO RETURN)

#include<stdio.h>
void sum (int a, int b);
void main()
{
   int a,b;
   printf("Enter Two Value");
   scanf("%d %d",&a,&b);
   sum(a,b); 
}
void sum (int a,int b);
{
    int c;
    c=a+b;
    printf("The Sum is %d",c);
}