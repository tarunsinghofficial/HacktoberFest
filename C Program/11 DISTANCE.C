// WAP TO CONVERT DISTANCE IN KM INTO M AND CM

#include<stdio.h>
int main()
{
    int m,c,k;   // m meter,c centimeter,k kilometer
    printf("Enter Distance In Kilometer");
    scanf("%d",&k);
    m=1000*k;
    c=100*1000*k; // or 100*m
    printf("Distance in Meter is %d",m);
    printf("\nDistance in Centimeter is %d",c);
    return 0;
}