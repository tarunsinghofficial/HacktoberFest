#include<stdio.h>
#include<conio.h>
void main()
{
    int n_1,n_2,n_3,temp,result;
    printf("enter the value of three numbers");
    scanf("%d%d%d,&n_1&n_2&n_3");
    temp = (n_1<n_2)?n_1:n_2;
    result = (temp<n_3)?temp:n_3;
    printf("smallest no. %d",result);
}