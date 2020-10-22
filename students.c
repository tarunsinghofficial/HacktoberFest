#include <stdio.h>
int main(int argc, char const *argv[])
{
    int a,b,n;
    printf ("enter rank from top \n");
    scanf ("%d" , &a);
    printf ("enter rank from bottom \n");
    scanf ("%d" ,&b);
    n = a+b-1;
    printf ("no of students= %d",n);
    return 0;
}
