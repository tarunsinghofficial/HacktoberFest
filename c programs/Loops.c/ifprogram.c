#include<stdio.h>
#include<conio.h>
 void main()
{
int a,b,c,d;
float ratio;
printf("enter the value of a,b,c,d:-\n");
scanf("%d%d%d%d,&a,&b,&c,&d");
if (c-d!=0)
 { 
    ratio= (float)(a+b)/(float)(c-d);
    printf("ratio=%f\n",&ratio);
 }
}