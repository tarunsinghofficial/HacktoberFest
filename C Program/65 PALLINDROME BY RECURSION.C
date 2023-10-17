// WAP TO CHECK THE NUMBER IS PALLINDROME OR NOT USING RECURSION

#include <stdio.h>

int rev(int n, int sum);
int pal(int n);

int main()
{
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);

    if (pal(n) == 1)
        printf("Palindrome\n");
    else
        printf("Not Palindrome\n");

    return 0;
}

int pal(int n)
{
    if (n == rev(n, 0))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int rev(int n, int sum)
{
    if (n != 0)
    {
        int r = n % 10;
        sum = sum * 10 + r;
        return rev(n / 10, sum);
    }
    else
    {
        return sum;
    }
}
