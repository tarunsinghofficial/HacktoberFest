#include <iostream>

// Define the structure for a linked list node
struct Node
{
    int data;
    Node *next;
    Node(int value) : data(value), next(nullptr) {}
};

// Function to print the linked list
void printList(Node *head)
{
    Node *current = head;
    while (current != nullptr)
    {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

// Function to reverse a linked list
Node *reverseList(Node *head)
{
    Node *prev = nullptr;
    Node *current = head;
    Node *next = nullptr;

    while (current != nullptr)
    {
        // Store the next node
        next = current->next;

        // Reverse the link
        current->next = prev;

        // Move pointers one step forward
        prev = current;
        current = next;
    }

    // Update the new head
    head = prev;
    return head;
}

int main()
{
    // Create a sample linked list: 1 -> 2 -> 3 -> 4 -> 5
    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    std::cout << "Original Linked List: ";
    printList(head);

    // Reverse the linked list
    head = reverseList(head);

    std::cout << "Reversed Linked List: ";
    printList(head);

    return 0;
}
