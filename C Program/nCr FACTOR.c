#include<stdio.h>
#include<conio.h>
int fact(int n)
 {
            int f=1;
            while(n>0)
            {
             f=f*n;
             n=n-1;
            }
  return f;
 }

void main()
 {
            int n,nCr,r;
            printf("\n\n\t\t\t nCr FACTOR\n");
            printf("\n\t\t\t*************\n");
            printf("\n\t\t Enter the n value:");
            scanf("%d",&n);
            printf("\n\t\t Enter the r value:");
            scanf("%d",&r);
            nCr=fact(n)/(fact(r)*fact(n-r));
            printf("\n\t\t nCr Factor=%d",nCr);
   getch();
 }
