#include <stdio.h>
#include <stdlib.h>

#define Max_Passenger 20
void vip_allocation();
void line_join();
void dequeue();
struct line
{
    int front;
    int rear;
    int passenger_count;
} members;
int main()
{
    members.front = -1;
    members.rear = -1;
    members.passenger_count = 0;
    int choice;
    do
    {
        printf("1. Join the line\n2. VIP ALLOCATION\n3. Exit\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            line_join();
            break;
        case 2:
            vip_allocation();
            break;
        case 3:
            printf("Thank you for riding!");
            exit(0);
        }
    } while (choice != 3);
}
void line_join()
{
    int Rollercoaster[20];
    int add_passenger;
    if ((members.rear == Max_Passenger - 1 && members.front == 0) || (members.rear == members.front-1))
    {
        // printf("!! RIDE IS FULL NEXT PASSENGER PLEASE WAIT FOR NEXT ROUND !! \n\n");
        // for (int i = 1; i <= 20; i++)
        // {
        //     dequeue();
        // }
        // printf("!! New Round Has Started !!\n");
        printf("\n");
    }
    else if ((members.rear == (Max_Passenger - 1)) && (members.front != 0))
    {
        members.rear = 0;
        printf("Enter your ticket number: ");
        scanf("%d", &add_passenger);
    }
    else
    {
        if (members.front == -1)
            members.front = 0;
        printf("Enter your ticket number: ");
        scanf("%d", &add_passenger);
        members.rear++;
        printf("!! Welcome to the ride. Enjoy the ride !! \n\n");
    }
    members.passenger_count++;
    Rollercoaster[members.rear] = add_passenger;
    if ((members.rear == Max_Passenger - 1 && members.front == 0) || (members.rear == members.front-1))
    {
        printf("!! RIDE IS FULL NEXT PASSENGER PLEASE WAIT FOR NEXT ROUND !! \n\n");
        for (int i = 1; i <= 20; i++)
        {
            dequeue();
        }
        printf("!! New Round Has Started !!\n\n");
    }
}
void dequeue()
{
    if (members.front == members.rear)
    {
        members.front = -1;
        members.rear = -1;
    }
    else if (members.front == Max_Passenger - 1)
    {
        members.front = 0;
    }
    else
    {
        members.front += 1;
    }
    members.passenger_count--;
}

void vip_allocation()
{
    int vip;
    printf("Number of VIP members:");
    scanf("%d", &vip);
    int seats_left = 20 - members.passenger_count;
    if (seats_left < vip)
    {
        for (int i = 1; i <= (vip - seats_left); i++)
        {
            dequeue();
        }
        printf("%d VIP seats have been vacated and are ready!\n", vip);
    }
    else
    {
        printf("%d VIP seats are already vacant!\n", vip);
    }
    printf("VIP members join one by one by using '1' option.\n");
}