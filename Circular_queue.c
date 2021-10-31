#include<stdio.h>

// declaring the recursive function
int find_gcd(int , int );

int main()
{
    printf("\n\n\t\tStudytonight - Best place to learn\n\n\n");
    int a, b, gcd;
    printf("\n\nEnter two numbers to find GCD of \n");
    scanf("%d%d", &a, &b);
    gcd = find_gcd(a, b);
    printf("\n\nGCD of %d and %d is: %d\n\n", a, b, gcd);
    printf("\n\n\t\t\tCoding is Fun !\n\n\n");
    return 0;
}

// defining the function
int find_gcd(int x, int y)
{
    if(x > y)
        find_gcd(x-y, y);

    else if(y > x)
        find_gcd(x, y-x);
    else
    return x;
}


INSERT 
void insert(int item)
{
if((front == 0 && rear == MAX-1) || (front == rear+1))
{
printf("Queue Overflow n");
return;
}
if(front == -1)
{
front = 0;
rear = 0;
}
else
{
if(rear == MAX-1)
rear = 0;
else
rear = rear+1;
}
cqueue_arr[rear] = item ;
}

DELETE
void deletion()
{
if(front == -1)
{
printf("Queue Underflown");
return;
}
printf("Element deleted from queue is : %dn",cqueue_arr[front]);
if(front == rear)
{
front = -1;
rear=-1;
}
else
{
if(front == MAX-1)
front = 0;
else
front = front+1;
}
}


DISPLAY
void display()
{
int front_pos = front,rear_pos = rear;
if(front == -1)
{
printf("Queue is emptyn");
return;
}
printf("Queue elements :n");
if( front_pos <= rear_pos )
while(front_pos <= rear_pos)
{
printf("%d ",cqueue_arr[front_pos]);
front_pos++;
}
else
{
while(front_pos <= MAX-1)
{
printf("%d ",cqueue_arr[front_pos]);
front_pos++;
}
front_pos = 0;
while(front_pos <= rear_pos)
{
printf("%d ",cqueue_arr[front_pos]);
front_pos++;
}
}
printf("n");
}