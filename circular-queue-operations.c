# include<stdio.h>
# define MAX 100

int cqueue_arr[MAX];
int front = -1;
int rear = -1;
int n;

void insert(int item)
{
if((front == 0 && rear == n-1) || (front == n+1))
{
printf("Queue Overflow \n");
return;
}
if (front == -1) 
{
front = 0;
rear = 0;
}
else
{
if(rear == n-1)
rear = 0;
else
rear = rear+1;
}
cqueue_arr[rear] = item ;
}

void del()
{
if (front == -1)
{
printf("Queue Underflow\n");
return ;
}
printf("Element deleted from queue is : %d\n",cqueue_arr[front]);
if(front == rear) 
{
front = -1;
rear=-1;
}
else
{
if(front == n-1)
front = 0;
else
front = front+1;
}
}

void display()
{
int front_pos = front,rear_pos = rear;
if(front == -1)
{
printf("Queue is empty\n");
return;
}
printf("Queue elements : ");
if( front_pos <= rear_pos )
while(front_pos <= rear_pos)
{
printf("%d ",cqueue_arr[front_pos]);
front_pos++;
}
else
{
while(front_pos <= n-1)
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
printf("\n");
}

void peek()
{
if(front == -1)
{
printf("Queue is empty\n");
}
else 
printf("Peek : %d\n",cqueue_arr[front]);
}

void isempty()
{
if(front == -1)
{
printf("Queue is empty\n");
}
else
printf("Queue is not empty\n");
}

void isfull()
{
if((front == 0 && rear == n-1) || (front == n+1))
{
printf("Queue is full \n");
}
else 
printf("Queue is not full\n");
}

int main()
{
int choice,item;
printf("Enter the size of the circular queue : ");
scanf("%d",&n);
int cqueue_arr[n];
printf("1.Insert\n");
printf("2.Delete\n");
printf("3.Display\n");
printf("4.Peek\n");
do
{

printf("Enter your choice : ");
scanf("%d",&choice);

switch(choice)
{
case 1 :
printf("Input the element for insertion in queue : ");
scanf("%d", &item);
insert(item);
break;
case 2 :
del();
break;
case 3:
display();
break;
case 4:
peek();
break; 
default:
printf("Wrong choice\n");
}
}
while(choice!=7);
return 0;
}
