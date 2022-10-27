//wap to calculate the sum of m natural number occuring in the table of n
#include<stdio.h>
#include<conio.h>
void main(){
    int n,m,sum,i,a;
    printf("Enter the m natural number you want to add");
    scanf("%d",&m);
    printf("Enter the n numberof table ");
    scanf("%d",&n);
    sum=0;
    for(i=0;i<=m;i++){
        a=n*i;
        sum=sum+a;
    }
    printf("The sum of %d natural number ",m);
    printf(" in the table of %d is",n);
    printf("%d",sum);
}