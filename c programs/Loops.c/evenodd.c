#include<stdio.h>
#include<conio.h>
int main(){
    int a ;
    printf("enter a positive interger\n");
    scanf("%d",&a);

    if(a < 0){
        printf("you have entered a negative number\n");
         printf("to prceed the program enter a positive number\n");
    }
    else{
    if (a % 2 ==0){
        printf("the no.%d is even\n",a);
    }else{
        printf("the no. %d is odd\n",a);
    }
    }

}