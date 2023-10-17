/* WAP TO SHOW THE WORKING OF LOGICAL OPERATOR i.e., &&,||,!
NOTE :- IT RETURN 1 IF CONDITION IS TRUE AND 0 IF CONDITION IS FALSE */

#include<stdio.h>
int main()
{
    // LOGICAL AND &&

    int a,b,c,d,f;
    a=2,b=5,c=8,d=7;
    f=(a<b)&&(c>d);   // BOTH CONDITION SHOULD BE TRUE
    printf("%d",f);

    // LOGICAL OR ||

    int g,h,i,j,k;
    g=6,h=8,i=4,j=9;
    k=(g<h)||(i>j);  // AT LEAST ONE CONDITION SHOULD BE TRUE
    printf("\n%d",k);

    // LOGICAL NOT !

    int l,m,p;
    l=9,m=7;
    p=!(l>m); // IT RETURNS INVERSE OF ANSWER
    printf("\n%d",p);

}