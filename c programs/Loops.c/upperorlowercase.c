#include<stdio.h>
#include<conio.h>
void main()
{
    char ch;
    printf("enter the character");
    scanf("%c",&ch);
    if (ch >= 'A' && ch <= 'Z'){
        printf("the character is upper case");
    }
    else if(ch >= 'a'&& ch <='z'){
        printf("the character is lower case");
    }
    else{
        printf("the character is not of english language");
    }
}
