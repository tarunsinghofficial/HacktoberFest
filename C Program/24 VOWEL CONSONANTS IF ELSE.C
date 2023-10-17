// WAP TO CHECK THE ENTERED ALPHABET IS VOWEL OR CONSONANTS USING IF ELSE

#include<stdio.h>
int main()
{
    char a;
    printf("Enter Alphabet");
    scanf(" %c",&a);
    if (a=='a'||a=='A'||a=='e'||a=='E'||a=='i'||a=='I'||a=='o'||a=='O'||a=='u'||a=='U')
    {
        printf("Entered Alphabet is Vowel");
    }
    else
    {
        printf("Entered Alphabet is Consonants");
    }
    return 0;
}