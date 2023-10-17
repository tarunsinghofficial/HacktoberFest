// WAP TO CHECK THE ENTERED ALPHABET IS VOWEL OR CONSONANTS USING SWITCH CASE

#include<stdio.h>
int main()
{
    char a;
    printf("Enter Alphabet");
    scanf(" %c",&a);
    switch(a)
    {
        case 'a': printf("Entered Alphabet is Vowel");
        break;
        case 'A': printf("Entered Alphabet is Vowel");
        break;
        case 'e': printf("Entered Alphabet is Vowel");
        break;
        case 'E': printf("Entered Alphabet is Vowel");
        break;
        case 'i': printf("Entered Alphabet is Vowel");
        break;
        case 'I': printf("Entered Alphabet is Vowel");
        break;
        case 'o': printf("Entered Alphabet is Vowel");
        break;
        case 'O': printf("Entered Alphabet is Vowel");
        break;
        case 'u': printf("Entered Alphabet is Vowel");
        break;
        case 'U': printf("Entered Alphabet is Vowel");
        break;
        default: printf("Entered Alphabet is Consonants");
    }
    return 0;
}