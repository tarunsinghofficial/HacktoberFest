#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
struct ListNode{
    int data;
    struct ListNode* next;
};
bool hasCycle(struct ListNode *head) {
    if(head==NULL||head->next==NULL) 
    {
    return false;
    } 
 struct ListNode* ptr=(struct ListNode*)malloc(sizeof(struct ListNode*));
 struct ListNode* ptrf=(struct ListNode*)malloc(sizeof(struct ListNode*));
    ptrf=head;
    ptr=head->next;  
  while(ptr!=NULL && ptr->next != NULL)
   {
   if(ptrf == ptr)
   {
    return true;
   }
   ptrf=ptrf->next;
   ptr=ptr->next->next;
   }
   return false;
}
int main()
{
    struct ListNode * head = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode * secondNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode * thirdNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode * fourthNode = (struct ListNode*)malloc(sizeof(struct ListNode));

    head->data = 3;
    head->next = secondNode;

    secondNode->data = 6;
    secondNode->next = thirdNode;

    thirdNode->data = 0;
    thirdNode->next = fourthNode;

    fourthNode->data = -2;
    fourthNode->next = NULL;
    bool h;
    h = hasCycle(head);
    printf("%d", h);
    return 0;
}