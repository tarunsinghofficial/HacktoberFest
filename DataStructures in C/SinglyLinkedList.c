#include <stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};

typedef struct node NODE;

NODE *START; 

void createEmptyList(){
    START = NULL;
}

void insertAtBeggining(int item){
        NODE *newNode;
        newNode =(NODE*) malloc(sizeof(NODE));
        newNode->data = item;

        if(START==(NODE*)NULL){
            START = newNode;
            START->next = (NODE*)NULL;
            return;
        }

        newNode->next = START;
        START = newNode;
}

void insertAtEnd(int item){
    NODE *newNode;
    newNode =(NODE*) malloc(sizeof(NODE));
    newNode->data=item;
    newNode->next = NULL;

    if(START==NULL){
        START=newNode;   
        return;
    }  

    NODE *temp = START;

    while(temp->next!=NULL){
        temp = temp->next;
    }

    temp->next = newNode;

}

void insertAtSpe(int item, int pos){
    if(START==NULL){
        printf("No such position found...\n");
        return;
    }

    NODE *temp = START;

    for(int i=1; i<pos-1; i++){
        temp = temp->next;
        if(temp==(NODE*)NULL){
            printf("No such position found....");
            return;
        }
    }
    NODE *newNode;
    newNode = (NODE*)malloc(sizeof(NODE));
    newNode->data = item;
    newNode->next = temp->next;
    temp->next = newNode;
}

void traverse(){
    NODE *temp = START;

    if(START==(NODE*)NULL){
        printf("List is empty....");
        return;
    }

    while(temp!=(NODE*)NULL){
        printf("%d\n",temp->data);
        temp = temp->next;
    }
}

void delete(int item){
   
    if(item==START->data){
        NODE *temp = START;
        START= START->next;
        free(temp);
        return;
    }
  
    NODE *temp;
    temp = START;


    while(temp->next->data!=item){

            temp = temp->next;
            if(temp->next == NULL){
                printf("No such data found....");
                return;
            }
    }
    NODE *p = temp->next;
    temp->next = temp->next->next;
    free(p);
   
}

void search(int item){
    NODE *temp = START;
    int i=1;
   
    while(temp->data!=item){
        if(temp->next==NULL){
            printf("data not found\n");
            return;
        }
        temp=temp->next;
        i++;
    }

    printf("%d found in position %d\n",item,i);
}


int main(){
    int choice , item , pos;
    createEmptyList();
    while(1){
    printf("What do you want to perform?\n1.Insertion at Beginning\n2.Traverse\n3.Insertion at End\n4.Insertion at Specified Position\n5.Delete data\n6.Searching data\n7.Exit\nEnter your choice:\n");
    scanf("%d",&choice);

    switch(choice){
        case 1: 
                printf("Enter data to insert : ");
                scanf("%d",&item);
                insertAtBeggining(item);
                break;

        case 2: 
                traverse();
                break;

        case 3: 
                printf("Enter data to insert: ");
                scanf("%d",&item);
                insertAtEnd(item);
                break;

        case 4:
                printf("Enter data to insert and position: ");
                scanf("%d%d",&item,&pos);
                insertAtSpe(item,pos);
                break;

        case 5: printf("Enter data to delete :");
                scanf("%d",&item);
                delete(item);
                break;

        case 6:
                printf("Enter data to search: \n");
                scanf("%d",&item);
                search(item);
                break;

        case 7: return 0;
        default:
                printf("Wrong choice\n");
    }
    }
}