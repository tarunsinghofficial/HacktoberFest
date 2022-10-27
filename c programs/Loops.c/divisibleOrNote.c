// Wap to check wheter the number is divisible by 106 or not
#include<stdio.h>// header file for taking input and giving output
void main(){
    int num;
    printf("write a number you want to check");
    scanf("%d",&num);
    if(num%106==0){
        printf("%d number is divisible by 106",num);
        }
        else{
        printf("%d is not divisible by 106",num);
        }
    }
