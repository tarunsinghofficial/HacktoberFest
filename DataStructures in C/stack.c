#include <stdio.h>
#define SIZE 10
int stack[SIZE];
int top=-1;


int isEmpty(){

    int x = top==-1?1:0;
    return x;
}

int isFull(){
    int x = top==(SIZE-1)?1:0;
    return x;
}

void push(int data){
    if(isFull()){
            printf("Stack overflow...");
            return;
    }

    top++;
    stack[top] = data;
}

void pop(){
    if(isEmpty()){
        printf("Stack underflow...");
        return;
    }

    int data = stack[top];
    top--;

    printf("Popped data : %d",data);
}

void traverse(){
    if(isEmpty()){
        printf("Stack underflow...");
        return;
    }

    printf("The stack elements are :");
    for(int i=top;i>=0;i--){
        printf("\n%d",stack[i]);
    }
}


int main(){
        int choice, data;

        while(1){
            printf("What do you want to perform?\n1.Push\n2.Pop\n3.Traverse\n4.Exit\nEnter your choice:\n");
            scanf("%d",&choice);

            switch(choice){
                case 1: printf("Enter data to push : ");
                        scanf("%d",&data);
                        push(data);
                        break;
                case 2: pop();
                        break;
                case 3: traverse();
                        break;
                case 4: return 0;
                default: printf("Wrong choice...");
            }

        }
    return 0;
}

