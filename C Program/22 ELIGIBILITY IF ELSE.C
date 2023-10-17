// WAP TO CHECK WETHER THE MALE OR FEMALE IS ELIGIBLE FOR MARRIAGE OR NOT

#include<stdio.h>
int main()
{
    int age;
    printf("Enter Your Age");
    scanf("%d",&age);
    if (age>=21)
    {
        printf("Congratulation You Are Eligible for Marriage");
    }
    else
    {
        printf("So Sad You Are Not Eligible For Marriage");
    }
    return 0;
}