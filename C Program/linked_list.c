#include <stdio.h>
#include <stdlib.h>

struct node {
  int data;
  struct node* next;
}*tmp,*nn,*head;

int main() {
  int n;
  printf("Enter the no of elements");
  scanf("%d",&n);

  for(int i=0; i<n; i++) {
        nn = (struct node *)malloc(sizeof(struct node));
        printf("Enter the data");
        scanf("%d",&nn->data);
        if(head == 0) {
            head = tmp = nn;
        }else{
            tmp->next = nn;
            tmp = nn;
        }
  }
  tmp = head;
  while(tmp != 0) {
      printf("%d",tmp->data);
      tmp = tmp->next;
  }
  return 0;
}
