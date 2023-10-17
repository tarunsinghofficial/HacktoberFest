#include <stdio.h>

int reverse(int n);

int main()
{
    int n, reversed;
    printf("Enter The Number: ");
    scanf("%d", &n);
    reversed = reverse(n);
    printf("The Reverse Of Number is %d", reversed);
    return 0;
}

int reverse(int n)
{
    static int sum = 0; // Using a static variable to store the reversed number
    if (n != 0)
    {
        int a = n % 10;
        sum = sum * 10 + a;
        reverse(n / 10);
    }
    return sum;
}