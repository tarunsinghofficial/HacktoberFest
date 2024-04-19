/*
 * C Program to Convert Binary to Hexadecimal 
 Enter the binary number: 10000
Equivalent hexadecimal value: 10
 */
#include <stdio.h>
 
int main()
{
    long int binaryval, hexadecimalval = 0, i = 1, remainder;
 
    printf("Enter the binary number: ");
    scanf("%ld", &binaryval);
    while (binaryval != 0)
    {
        remainder = binaryval % 10;
        hexadecimalval = hexadecimalval + remainder * i;
        i = i * 2;
        binaryval = binaryval / 10;
    }
    printf("Equivalent hexadecimal value: %lX", hexadecimalval);
    return 0;
}
