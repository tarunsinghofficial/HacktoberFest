// WAP TO CHECK THE NUMBER IS PALLIDROME OR NOT USING FUNCTION WITH ARGUMENT BUT NO RETURN VALUE

#include<stdio.h>
int pal(int t);
int main()
{
    int n;
    printf("Enter Any Number");
    scanf("%d",&n);
    pal(n);
}
int pal(int n)
{
    int r,b=0,c;
    c=n;
    while(n>0)
    {
        r=n%10;
        b=b*10+r;
        n=n/10;
    }
    if (b==c)
    {
        printf("Pallindrome");
    }
    else
    {
        printf("Not a Pallindrome");
    }
}