//Wap to find the greatest numeber between four numbers
#include<stdio.h>
#include<conio.h>
void main(){
    int a,b,c,d;// a,b,c,d are the numbers 
    printf("Enter the numbers");
    scanf("%d%d%d%d",&a,&b,&c,&d);
    if(a>b){
        if(a>c){
            printf("%d is greatest",a);
        {
            if(a>d){
                printf("%d is greatest among all four numbers",a);
            }
            else{
                printf("%d is greatest among all four numbers",d);
            }
        }
    }
}
else if (b>a){
    if(b>c){
        if(b>d){
            printf("%d is greatest among all four numbers",b);
        }
            else{
                printf("%d is greatest among all four numbers",d);
            }
    }
}
else if(c>a){
    if(c>b){
        if(c>d){
            printf("%d is greatest among all four numbers",c);
        }
            else{
                printf("%d is greatest among all four numbers",d);
            }
    }
}
else{
    printf("%d is greatest among all four numbers");
}
}