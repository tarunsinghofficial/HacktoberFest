#include <stdio.h>
#include <stdlib.h>
char a[100], top = -1, n = 100;
void push(char ch)
{
    if (top == n - 1)
    {
        printf("\nStack Overflow");
        return;
    }
    top++;
    a[top] = ch;
}
void pop()
{
    if (top == -1)
    {
        printf("\nStack Underflow");
        return;
    }
    //printf("\nPopped Element =%d", a[top]);
    top--;
}
int Top()
{
    if (top == -1)
    {
        //printf("\nStack is Empty");
        return '\0';
    }
    return (a[top]);
}
int isEmpty()
{
    if (top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int preced(char ch)
{
    switch (ch)
    {
    case '^':
        return 3;
    case '/':
        return 2;
    case '*':
        return 2;
    case '+':
        return 1;
    case '-':
        return 1;
    default:
        return -1;
    }
}
char *InfixToPostfix(char *s)
{
    int i;
    int length = 0;
    for (i = 0; s[i] != '\0'; i++)
        ;
    int pos = -1;
    length = i;
    char *x = (char *)malloc(sizeof(char) * length);
    for (i = 0; i < length; i++)
    {
        if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= '0' && s[i] <= '9'))
        {
            x[++pos] = s[i];
        }
        else if (s[i] == '(')
        {
            push(s[i]);
        }
        else if (s[i] == ')')
        {
            while (a[top] != '(')
            {
                x[++pos] = a[top];
                //printf("%c",a[top]);
                pop();
            }
            pop();
        }
        else // symbol
        {
            while (isEmpty() == 0 && preced(a[top]) >= preced(s[i]))
            {
                x[++pos] = a[top];
                //printf("%c",a[top]);
                pop();
            }
            push(s[i]);
        }
    }
    while (isEmpty() == 0)
    {
        x[++pos] = a[top];
        // printf("%c",a[top]);
        pop();
    }

    return x;
}
int main()
{
    char exp[50];
   // printf("Enter The Infix Expression:");
    scanf("%s", exp);
    //   printf("%s",exp);

    char *output = InfixToPostfix(exp);
    for (int i = 0; output[i] != '\0'; i++)
    {
        printf("%c", output[i]);
    }
    printf("\n");
    return 0;
}
/*
                            This    Code     is     Written  by
 _____  _      _                      _                    ___         _
/  __ \| |    (_)                    | |                  / _ \       | |
| /  \/| |__   _  _ __   __ _  _ __  | |_   __ _  _ __   / /_\ \  ___ | |__    __ _  _ __  _   _  _   _   __ _
| |    | '_ \ | || '__| / _` || '_ \ | __| / _` || '_ \  |  _  | / __|| '_ \  / _` || '__|| | | || | | | / _` |
| \__/\| | | || || |   | (_| || | | || |_ | (_| || | | | | | | || (__ | | | || (_| || |   | |_| || |_| || (_| |
 \____/|_| |_||_||_|    \__,_||_| |_| \__| \__,_||_| |_| \_| |_/ \___||_| |_| \__,_||_|    \__, | \__, | \__,_|
                                                                                            __/ |  __/ |
                                                                                           |___/  |___/
*/