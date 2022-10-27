// wap to check whether a student is pass or fail
//pass above 40% and fail below 40%
#include<stdio.h>
#include<conio.h>
void main(){
    int Subject_1_marks ,Subject_2_marks,Subject_3_marks,Subject_4_marks,Subject_5_marks,OutOf,total_out_of_marks,total_gained_marks;
    float percentage;
    printf("Enter the marks of each subjects a student got in their examinations\n");
    printf("Subject_1_marks\n");
    scanf("%d",&Subject_1_marks);
    printf("Subject_2_marks\n"); 
    scanf("%d",&Subject_2_marks);
    printf("Subject_3_marks\n");
    scanf("%d",&Subject_3_marks);
    printf("Subject_4_marks\n");
    scanf("%d",&Subject_4_marks);
    printf("Subject_5_marks\n");
    scanf("%d",&Subject_5_marks);
    printf("OutOf\n");
    scanf("%d",&OutOf);
    total_gained_marks=Subject_1_marks+Subject_2_marks+Subject_3_marks+Subject_4_marks+Subject_5_marks;
    printf("total_gained_marks %d\n",total_gained_marks);
    total_out_of_marks= 5*OutOf;
    printf("total_out_of_marks%d\n",total_out_of_marks);
    percentage=(total_gained_marks*100)/total_out_of_marks;
    printf("percentage of student is%f",percentage);
    if(percentage>=40){
        printf("Student is pass"); 
    }
    else{
        printf("Student is fail");
    }
}