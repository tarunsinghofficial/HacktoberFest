#include <stdio.h>
#include <stdlib.h>

typedef struct treenode{
    int data;
    struct treenode *left;
    struct treenode *right;
}TREENODE;

TREENODE *root; 

void createRootNode(int data){
    root = malloc(sizeof(TREENODE));
    root->data = data;
    root->left = NULL;
    root->right = NULL;
}

void insertNewNode(int data){
    if(root==NULL){
        createRootNode(data);
        return;
    }

    TREENODE *newNode = malloc(sizeof(TREENODE));
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->data = data;
    
    TREENODE *temp = root;

    if(data==root->data){
        printf("No duplicate elements allowed in Binary Search Tree...\n");
        return;
    }

    if(data<temp->data){

        while(temp->left!=NULL){
            temp = temp->left;
            if(data<temp->data){
                temp = temp->left;
            } 
            else if(data>temp->data){
                temp = temp->right;
            }
            else{
                printf("No duplicate elements allowed in binary search tree...\n");
                return;
            }
        }

        if(data<temp->data){
            temp->left = newNode;
            
        }
        else if(data>temp->data){
            temp->right = newNode;
        }


    }

    else if(data>root->data){
        while(temp->right!=NULL){
            temp = temp->right;

            if(data<temp->data){
                temp = temp->left;
            }
            else if(data>temp->data){
                temp = temp->right;
            }
            else{
                printf("No duplicate nodes allowed in Binary Search Tree\n");
            }
        }
    }
}

//preorder traversal
void traverse(TREENODE *root){

    if(root==NULL) return;

    
    printf("%d---",root->data);
    traverse(root->left);
    traverse(root->right);
}


int main(){
    int choice , data;
    while(1){
        printf("What do you want to perform?\n1.Insertion\n2.Traversal:\n");
        scanf("%d",&choice);
        switch(choice){
            case 1: printf("Enter data : ");
                    scanf("%d",&data);
                    insertNewNode(data);
                    break;
            case 2: traverse(root);
                    break;
            default: printf("Please Enter valid choice....\n");
        }
    }
  
    return 0;
}