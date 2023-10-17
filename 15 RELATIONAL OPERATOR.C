/*  WAP TO SHOW THE WORKING OF RELATIONAL OPERATOR i.e., <,>,<=,>=,==,!=
NOTE :- IT RETURN 1 IF CONDITION IS TRUE AND 0 IF CONDITION IS FALSE */

#include<stdio.h>
int main()
{
    // less than

    int a,b,c;
    a=1,b=2;
    c=a<b;
    printf("%d",c);

    // greater than

    int d,e,f;
    d=2,e=1;
    f=d>e;
    printf("\n%d",f);

    // less than equal to

    int g,h,i;
    g=3,h=3;
    i=g<=h;
    printf("\n%d",i);

    // greater than equal to

    int j,k,l;
    j=4,k=4;
    l=j>=k;
    printf("\n%d",l);

    // equal to

    int m,n,o;
    m=2,n=2;
    o=m==n;
    printf("\n%d",o);

    // not equal to

    int p,q,r;
    p=2,q=3;
    r=p!=q;
    printf("\n%d",r);

    return 0;
    
}