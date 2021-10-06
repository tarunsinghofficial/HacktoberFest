#include<stdio.h>
int prime[100];int n;
void main()
{
    printf("Enter the limit till which prime numbers have to be printed");
    scanf("%d",&n);
    for(int x=1;x<=n;x++)
    {
        prime[x]=1;
    }
    for(int y=2;y*y<=n;y++)
    {
        if(prime[y]==1)
        {
            for(int z=y*y;z<=n;z+=y)
            {
                prime[z]=0;
            }
        }
    }
    for(int i=2;i<=n;i++)
    {
        if(prime[i]==1)
            printf("%d,",i);
    }
}
