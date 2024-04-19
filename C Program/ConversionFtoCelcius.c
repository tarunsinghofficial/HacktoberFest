#include<stdio.h>
#include<conio.h>
int main()
{
    float fahrenheit, celsius;
    printf("Enter Temperature Value (in Fahrenheit): ");
    scanf("%f", &fahrenheit);
    celsius = (fahrenheit-32)/1.8;
    printf("\nEquivalent Temperature (in Celsius) = %0.2f", celsius);
    getch();
    return 0;
}