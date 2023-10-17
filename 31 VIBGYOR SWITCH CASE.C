// WAP TO PRINT THE FULL FORM OF VIBGYOR USING SWITCH CASE

#include<stdio.h>
int main()
{
    char a;
    printf("Enter Any Alphabet Among VIBGYOR");
    scanf(" %c",&a);
    switch(a)
    {
        case 'v':printf("V Stands For Violet");
        break;
        case 'V':printf("V Stands For Violet");
        break;
        case 'i':printf("I Stands For Indigo");
        break;
        case 'I':printf("I Stands For Indigo");
        break;
        case 'b':printf("B Stands For Blue");
        break;
        case 'B':printf("B Stands For Blue");
        break;
        case 'g':printf("G Stands For Green");
        break;
        case 'G':printf("G Stands For Green");
        break;
        case 'y':printf("Y Stands For Yellow");
        break;
        case 'Y':printf("Y Stands For Yellow");
        break;
        case 'o':printf("O Stands For Orange");
        break;
        case 'O':printf("O Stands For Orange");
        break;
        case 'r':printf("R Stands For Red");
        break;
        case 'R':printf("R Stands For Red");
        break;
        default:printf("Invalid Choice");
        break;
    }
}