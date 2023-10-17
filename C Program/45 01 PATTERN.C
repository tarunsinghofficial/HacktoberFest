/* WAP TO PRINT PATTERN

*
**
***
****
*****

*/

#include<stdio.h>
int main()
{
    int i,j;
    for(i=1;i<=5;i++) // for row
    {
        for(j=1;j<=5;j++) // for coloumn
        {
         if(j<=i)
         {
            printf("*");
          }
        }
        {     printf("\n");
        }
    }
}