// WAP TO PRINT THE FULL FORM OF VIBGYOR USING LADDER IF ELSE

#include<stdio.h>
int main()
{
    char a;
    printf("Enter Any Alphabet Among VIBGYOR :");
    scanf(" %c",&a);
    if(a=='v'||a=='V')
    {
        printf("V Stands for Violet");
    }
    else if(a=='i'||a=='I')
    {
        printf("I Stands for Indigo");
    }
    else if(a=='b'||a=='B')
    {
        printf("B Stands for Blue");
    }
    else if(a=='g'||a=='G')
    {
        printf("G Stands for Green");
    }
    else if(a=='y'||a=='Y')
    {
        printf("Y Stands for Yellow");
    }
    else if(a=='o'||a=='O')
    {
        printf("O Stands for Orange");
    }
    else if(a=='r'||a=='R')
    {
        printf("R Stands for Red");
    }
}