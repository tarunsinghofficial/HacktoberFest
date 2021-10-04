#include<stdio.h>

// declaring the recursive function
int isPal(int );

/*
    global declaration to use the same value 
    in both the functions
*/
int n;

int main()
{
    printf("\n\n\t\tStudytonight - Best place to learn\n\n\n");
    int palindrome;
    printf("\n\nEnter a number to check for Palindrome: ");
    scanf("%d", &n);
    palindrome = isPal(n);
    if(palindrome == 1)
        printf("\n\n\n%d is palindrome\n\n", n);
    else
        printf("\n\n\n%d is not palindrome\n\n", n);

    printf("\n\n\t\t\tCoding is Fun !\n\n\n");
    return 0;
}

int isPal(int aj)
{
    static int sum = 0;
    if(aj != 0)
    {
        sum = sum *10 + aj%10;
        isPal(aj/10);   // recursive call same as while(n!=0) using loop
    }
    else if(sum == n)
        return 1;
    else
        return 0;
}
