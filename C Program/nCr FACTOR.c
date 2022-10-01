#include<stdio.h>
#include<conio.h>
typedef long long ll;

ll fact(ll n)
{
       ll f=1;
       for(ll i=1;i<=n/2;i++)
       {
        f*=i*(n+1-i);
       }
       if(n&1) f*=(n/2+1);
       return f;
 }

void main()
 {
       ll n,nCr,r;
       clrscr();
       
       printf("\n\n\t\t\t nCr FACTOR\n");
       printf("\n\t\t\t*************\n");
       printf("\n\t\t Enter the n value:");
       scanf("ll%d",&n);
       printf("\n\t\t Enter the r value:");
       scanf("ll%d",&r);
       
       nCr=fact(n)/(fact(r)*fact(n-r));
       printf("\n\t\t nCr Factor=%lld",nCr);
 
       getch();
 }
