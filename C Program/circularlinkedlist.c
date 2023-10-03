#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node in the circular linked list
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the end of the circular linked list
void insertEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        newNode->next = newNode; // Point to itself for a single node
    } else {
        struct Node* temp = *head;
        while (temp->next != *head) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = *head;
    }
}

// Function to delete a node by value from the circular linked list
void deleteNode(struct Node** head, int key) {
    if (*head == NULL) {
        printf("List is empty. Cannot delete.\n");
        return;
    }

    struct Node* curr = *head, *prev = NULL;

    // Find the node to be deleted and its previous node
    while (curr->data != key) {
        if (curr->next == *head) {
            printf("Node with data %d not found.\n", key);
            return;
        }
        prev = curr;
        curr = curr->next;
    }

    // If the node to be deleted is the only node in the list
    if (curr->next == *head && prev == NULL) {
        *head = NULL;
        free(curr);
        return;
    }

    // If the node to be deleted is the first node
    if (curr == *head) {
        prev = *head;
        while (prev->next != *head) {
            prev = prev->next;
        }
        *head = (*head)->next;
        prev->next = *head;
        free(curr);
    } else {
        prev->next = curr->next;
        free(curr);
    }
}

// Function to display the circular linked list
void display(struct Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node* temp = head;
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("\n");
}

int main() {
    struct Node* head = NULL;

    insertEnd(&head, 1);
    insertEnd(&head, 2);
    insertEnd(&head, 3);
    insertEnd(&head, 4);

    printf("Circular Linked List: ");
    display(head);

    deleteNode(&head, 2);
    printf("Circular Linked List after deleting 2: ");
    display(head);

    deleteNode(&head, 1);
    printf("Circular Linked List after deleting 1: ");
    display(head);

    deleteNode(&head, 4);
    printf("Circular Linked List after deleting 4: ");
    display(head);

    deleteNode(&head, 3);
    printf("Circular Linked List after deleting 3: ");
    display(head);

    return 0;
}
