//sum of n natural number using for loop
#include<stdio.h>
#include<conio.h>
void main(){
    int n,i,sum=0;
    printf("Enter the natural number you want to add\n");
    scanf("%d",&n);
    for(i=0;i<=n;i++){
    sum=sum+i;
    }
    printf("the sum of %d natural number is\n",n);
    printf("%d",sum);
}