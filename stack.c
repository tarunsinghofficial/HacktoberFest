#include<stdio.h>
#define N 5
int top=-1;
int stack[N];
void push(){
    int a;
    printf("Enter the number: \n");
    scanf("%d",&a);
    top++;
    stack[top]=a;
};

void pop(){
    printf("%d is poped\n",stack[top]);
    top--;
};

void peek(){
    printf("The Number on the top is %d\n",stack[top]);
};

void display(){
    printf("[ ");
    for(int i=0;i<(top+1);i++){
    printf("%d ",stack[i]);
    }
    printf("]");
}

int main()
{
    int i;
    int y=1;
    while(y>0){
    printf("please Enter your number:\n");
    printf("press 1 for push\n");
    printf("press 2 for pop\n");
    printf("press 3 for peek\n");
    printf("press 4 for display\n");
    printf("press 5 for exit\n");
    scanf("%d",&i);
    switch(i){
        case 1:
            push();
            if(top>=N){
            printf("StackOverflow\n");
            y=-1;
            }
            break;
        case 2:
            pop();
            if(top<=-1){
            printf("StackUnderflow\n");
            y=-1;
             }
            break;
        case 3:
            peek();
            break;
        case 4:
            display();
            break;
        case 5:
            printf("Bye Bye\n");
            y=-1;
            break;
        default :
            printf("Correct value nakh ne bro\n");
            break;
    }
    
    }
    return 0;
}
