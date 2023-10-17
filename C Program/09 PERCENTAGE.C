// WAP TO PRINT THE PERCENTAGE OF STUDENT OF 5 SUBJECT IF TOTAL MARKS IS 500

#include<stdio.h>
int main()
{
    int s1,s2,s3,s4,s5,total; // s1,s2,s3,s4,s5 for subjects 1,2,3,4,5 and total for total marks
    int per; // per for percentage
    printf("Enter The Marks of 5 subjects");
    scanf("%d %d %d %d %d",&s1,&s2,&s3,&s4,&s5);
    printf("Marks Given By You is %d,%d,%d,%d,%d",s1,s2,s3,s4,s5);
    total=s1+s2+s3+s4+s5;
    printf("\nTotal Marks is %d",total);
    per=total/5;
    printf("\nPercentage of Marks is %d",per);
    return 0;
}