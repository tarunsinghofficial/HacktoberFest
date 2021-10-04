#include <stdio.h>
#include <math.h> //Importing the libraries
double sum1(int n, int x)             //Fuction to produce 1 + x + 2x + 3x.. upto n
{
    double res = 1;                    
    for (int i = 0; i <= n; i++)    //Loop to produce sum upto to n  
    {
        res = res + (i * x);         //Producing sum
    }
    return res;
}
double sum2(int n, int x)              ///Fuction to produce 1 + x/2 + 2x/3 + 3x/4.. upto n
{
    double res = 1;
    for (int i = 0; i <= n; i++)        //Loop to produce sum upto to n    
    {
        res = res + ((i * x) / (i + 1)); //Producing sum
    }
    return res;
}
int main()                             //Main function
{
    int x;                              //Variable of equation
    printf("Enter the value of x: ");   //Inputting the value of variable
    scanf("%d", &x);
    int n;                              //Coefficient of equation
    printf("Enter the value of n: ");   //Inputting the value of coefficient
    scanf("%d", &n);
    printf("1 + x + 2x + 3x... = %f\n", sum1(x, n));    //Calling the function sum1
    printf("1 + x/2 + 2x/3 + 3x/4.. = %f", sum2(x, n)); //Calling the function sum2
    return 0;
}
