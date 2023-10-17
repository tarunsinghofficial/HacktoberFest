// WAP TO READ AND WRITE 2-D ARRAY

#include<stdio.h>
int main()
{
    int i,j,r,c,a[10][10];
    printf("Enter Number Of Row And Column");
    scanf("%d %d",&r,&c);
    printf("Enter Elements");
    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
            scanf("%d",a[i][j]);
        }
    }
    printf("Elements Are");
    {
        for(i=0;i<r;i++)
        {
            for(j=0;j<c;j++)
            {
                printf("%d",a[i][j]);
            }
            printf("\n");
        }
    }
}