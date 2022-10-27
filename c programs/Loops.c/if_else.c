#include<stdio.h>
#include<conio.h>
void main()
{
    int marks;
    printf("DISTRIBUTION OF THE GRADES\n");
    printf("enter your marks\n");
    scanf("%d",&marks);
    if(marks < 30 ){
        printf("C\n");
    }
    else if (marks >=30 && marks<70){
        printf("B\n");
    }
    else if (marks >=70 && marks<90){
        printf("A\n");

    }
    else{
        printf("A+\n");
    }
}