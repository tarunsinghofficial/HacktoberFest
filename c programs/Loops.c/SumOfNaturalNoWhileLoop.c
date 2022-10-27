//Wap to print the sum of n natural numbers
#include<stdio.h>
#include<conio.h>
void main(){
    int n , i, sum ;
    printf("Enter natural number you want to add ");
    scanf("%d",&n);
    sum=0;
    i=0;
    while(i<=n)// natural number does not include negative numbers and 0 in it
    {
        sum = sum + i;
        i++;
    }
    printf("The sum of first %d natural numebers is",&n);
    printf("%d", sum);

}