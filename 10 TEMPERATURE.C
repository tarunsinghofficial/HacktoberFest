// WAP TO PRINT TEMPERATURE IN FAHRENHITE WHERE IN CELCIUS ENTERED BY USER

#include<stdio.h>
int main()
{
    float c,f,x; // c for celcius,f for fahrenhite,x for calculation 
    printf("Enter temperature in celcius");
    scanf("%f",&c);
    x=(c*1.8);
    f=32+x;
    printf("Temperature in Fahrenhite is %f",f);
    return 0;
}