#include <stdio.h>
#define SIZE 15

int stack[SIZE];
int top = -1;

int isfull() {
    if(top == SIZE-1) {
          return 1;
    }else{
          return 0;
    }
}

int isempty() {
    if(top == -1) {
          return 1;
    }else{
          return 0;
    }
}

void push(int data) {
  if(isfull(stack)) {
    printf("Stack is Full");
  }else{
    stack[top] = data;
    top++;
  }
}

void pop() {
    if(isempty(stack)){
      printf("Stack is Empty");
    }else{
    top--;
    stack[top] = 0;
    }
}

int main() {
    push(5);
    push(26);
    push(34);
    pop();
    push(8);
    pop();
    pop();
    push(55);
    push(16);


    for(int i=top-1; i>-1; i--) {
                printf("%d",stack[i]);
    }
    return 0;
}
