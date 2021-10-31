#include<stdio.h>
#define MAX 20
typedef struct stack
{
	char s[MAX];
	int top;
}STACK;
void initStack(STACK *ps)
{
	ps->top=-1;
}

int isFull(STACK *ps)
{
	return ps->top==MAX-1;
}
void push(STACK *ps,char ele)
{
	ps->s[++ps->top]=ele;
}
int isEmpty(STACK *ps)
{
	return ps->top==-1;
}
char pop(STACK *ps)
{
	return ps->s[ps->top--];	
}
int parenthesesMatch(char *str)
{
	STACK s;
	initStack(&s);
	
	for(int i=0;str[i]!='\0';i++)
	{
		if(str[i]=='(' || str[i]=='[' || str[i]=='{')
			push(&s,str[i]);
		else if(str[i]==')' || str[i]==']' || str[i]=='}')
		{
			if(isEmpty(&s))
				return 0;
			switch(str[i])
			{
				case ')':if(pop(&s)!='(')
							return 0;
						break;
				case ']':if(pop(&s)!='[')
							return 0;
						break;
				case '}':if(pop(&s)!='{')
							return 0;
						break;
			}
		}
	}
	return isEmpty(&s);
}
int main()
{
	char input[MAX];
	printf("Enter a parenthesized expression\n");
	scanf("%s",input);
	if(parenthesesMatch(input))
		printf("Valid expression\n");
	else
		printf("Invalid expression\n");
	return 0;
}