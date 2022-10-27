//wap to calculate a factorial of n number using for loop
#include<stdio.h>
#include<conio.h>
void main(){
    int n,i,factorial=1;
    printf("Enter the number of which you want to calculate the factorial");
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        factorial= factorial*i;
    }
    printf("The factorial of %d number is",n);
    printf("%d",factorial);
}