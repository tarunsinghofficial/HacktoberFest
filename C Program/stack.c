#include <stdio.h>
#include<stdlib.h>
int stack[4];
int top = -1;

void push()
{

if (top==4)
{
    printf("\nStackOverFlow Cannot Insert More Elements");
    exit(0);
}

    else
    {  
        
        int item;
        printf("Enter value You want to Enter in stack:");
        scanf("%d", &item);
        top++; 
        stack[top] = item;

    }
    }
        
void pop()
{
    if(top==-1)
    {
  printf("Stack is already Empty\n");

    }
    else
    {
        printf("Element %d is deleted",stack[top]);
        top-=1;
    }
    
}
int Top()
{
    return stack[top];
}
void display()
{
    printf("______\n");
for (int i = top; i >=0; i--)
{
    /* code */
    printf("|_%d_|\n",stack[i]);
}

}

int main()
{
    int ch;
    
    do{    
    printf("\nEnter Your Choice\n1.Insert\n2.Delete\n3.Elements in Stack\n4. End The Program Do-nothing\n5.Element at top \n6.To Check If Stack is Empty\n");
    scanf("%d", &ch);
        switch (ch)
        {
        case 1:
       {     push();
        
       }
            break;
        case 2:
            pop();
            break;

        case 3:
            printf("Elements Are : \n");
            display();
            break;
        case 4:
             printf("\nThanks.... will catch up you later...");
             exit(0);
             break;
        case 5:
        {int p=Top();
        printf("The value at top is : ");
        printf("%d",p);
        }
        break;
        case 6:
        
        break;
        default:
            printf("Enter Valid Choice\n");
            break;
        }
    }while(ch!=4);
    return 0;
}
