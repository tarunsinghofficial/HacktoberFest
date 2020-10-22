#include <stdio.h>

long fact(int);

int main()

{

int n, i, j;

printf(“Please enter number of rows you would like to see in pascal triangle\n”);

scanf(“%d”,&n);

printf(“Pascal Triangle pattern:\n”);

 

for ( i = 0 ; i < n ; i++ )

{

for ( j = 0 ; j <= ( n – i – 2 ) ; j++ )

printf(” “);

 

for( j = 0 ; j <= i ; j++ )


printf(“%ld “,fact(i)/(fact(j)*fact(i-j)));

 

printf(“\n”);

}

 

return 0;

}

 

long fact(int n)

{

int c;

long result = 1;

 

for( c = 1 ; c <= n ; c++ )

{

result = result*c;

}

return ( result );

}
