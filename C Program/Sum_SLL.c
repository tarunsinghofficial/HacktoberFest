#include <stdio.h>
#include <stdlib.h>

struct Node
{
   int data;
   struct Node *next;
};
int main()
{
   int i, n, item;
   struct Node *p, *q, *head;
   printf("\n\n----C program to find the sum of all the nodes in LINEAR LINKED_LIST----\n\n");
   printf("Enter the number of nodes : ");
   scanf("%d", &n);
   printf("Enter the value of head node : ");
   scanf("%d", &item);

   q = (struct Node *)malloc(sizeof(struct Node));
   q->data = item;
   q->next = NULL;

   head = q;
   p = head;
   for (i = 1; i < n; i++)
   {
      printf("Enter the value of %d node : ", i);
      scanf("%d", &item);
      q = (struct Node *)malloc(sizeof(struct Node));
      q->data = item;
      q->next = NULL;

      p->next = q;
      p = p->next;
   }

   p = head;
   printf("\nThe entered nodes are-\n");
   while (p != 0)
   {
      printf("%d ", p->data);
      p = p->next;
   }
   p = head;
   int sum = 0;
   printf("\n\nThe sum of all the elements in the linked list is : ");
   while (p != 0)
   {
      sum = sum + p->data;
      p = p->next;
   }
   printf("%d\n\n", sum);
   return 0;
}
