//WAP to print the sum of n natural numbers
#include<stdio.h>
#include<conio.h>
void main(){
    int n,i,sum=0;
    printf("Enter the number you want to add\n");
    scanf("%d",&n);
    i=0;
    do{
        sum=sum+i;
        i++;
    }
    while(i<=n);
    printf("the sum of %d natural number is\n",n);
    printf("%d",sum);
}