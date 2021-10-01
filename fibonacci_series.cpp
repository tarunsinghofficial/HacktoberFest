#include<stdio.h>    
int main()    
{    
 int num1=0,num2=1,num3,i,number;    
 printf(" Enter the number of elements:");    
 scanf("%d",&number);    
 printf("\n%d %d",num1,num2);//printing 0 and 1 before hand   
 for(i=2;i<number;++i)//loop starts from 2 because 0 and 1 are going to be printed    
 {    
  num3=numm1+num2;    
  printf(" %d",num3);    
  num1=num2;    
  num2=num3;    
 }  
  return 0;  
 }    