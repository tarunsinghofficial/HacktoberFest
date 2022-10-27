//wap to calculate the factorial of n number using do while loop
#include<stdio.h>
#include<conio.h>
void main(){
    int i,n,factorail=1;
    printf("Enter the number of which you want to calculate the factorial");
    scanf("%d",&n);
    i=1;
    do{
        factorail=factorail*i;
        i++;

    }
    while(i<=n);
    printf("The factorial of %d number is %d",n,factorail);
}
