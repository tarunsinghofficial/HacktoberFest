// WAP TO CALCULATE SIMPLE INTEREST

#include<stdio.h>
int main()
{
    int p,i,t,s; // p for Principal, i for Interest, t for Time, s for Simple interest
    printf("Enter Principal Amount");
    scanf("%d",&p);
    printf("\nEnter Rate of Interest");
    scanf("%d",&i);
    printf("\nEnter Time Taken");
    scanf("%d",&t);
    s=(p*i*t)/100;
    printf("Simple Interest Is %d",s);
    return 0;

}