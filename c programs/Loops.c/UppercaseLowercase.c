// C implementation of the above approach
#include <stdio.h>

void main()
{
    char ch;
    printf("Enter the alphabet\n");
    scanf("%c",&ch);

	if (ch >= 'A' && ch <= 'Z')
		printf("\n%c is an UpperCase character",ch);

	else if (ch >= 'a' && ch <= 'z')
		printf("\n%c is an LowerCase character",ch);

	else
		printf("\n%c is not an aplhabetic character",ch);
}


