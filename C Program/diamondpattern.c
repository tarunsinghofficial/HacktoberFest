#include <stdio.h>
int main()
{
    int i, j, n;
    scanf("%d", &n);
    for(i = 0; i < n; i++) 
    {
        for(j = 0; j < (2 * n); j++)
        { 
            if(i + j <= n - 1) 
                printf("*");
            else
                printf(" ");
            if((i + n) <= j)
                printf("*");
            else
                printf(" ");
        }
        printf("\n");
    }
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < (2 * n); j++)
        {
            if(i >= j) 
                printf("*");
            else
                printf(" ");
            if(i >= (2 * n - 1) - j)  
                printf("*");
            else
                printf(" ");
        }
        printf("\n");
    }
    return 0;
}
