#include <iostream>
#include <stdlib.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        next = nullptr;
    }
};

void input(Node **head)
{

    int n;
    cin >> n;

    Node *newNode = nullptr, *prev = nullptr;

    int tmp;

    for (int i = 0; i < n; i++)
    {
        cin >> tmp;
        newNode = new Node(tmp);
        if (i == 0)
        {
            *head = newNode;
            prev = *head;
            continue;
        }
        // else:-
        prev->next = newNode;
        prev = prev->next;
    }
    prev->next = nullptr;

    return;
}

void printList(Node *head)
{
    while (head)
    {
        cout << head->data << " --> ";
        head = head->next;
    }
    cout << "NULL";
    return;
}

void revList(Node **head)
{
    Node *curr = *head, *prev = nullptr, *right = nullptr;

    while (curr != nullptr)
    {
        // saving the future nodes
        right = curr->next;
        // breaking and reversing bond
        curr->next = prev;
        // propagating
        prev = curr;
        curr = right;
    }

    // new head is the tail;
    *head = prev;

    return;
}

void freeList(Node **head)
{
    Node *tmp;
    while (*head)
    {
        tmp = (*head)->next;
        (*head)->next = nullptr;
        free(*head);
        *head = tmp;
    }
    return;
}

int lenList(Node *head)
{
    int counter = 0;
    while (head != nullptr)
    {
        head = head->next;
        counter++;
    }
    return counter;
}

void delNode(Node *tmp)
{
    Node *right = tmp->next->next;
    tmp->next->next = nullptr;
    free(tmp->next);
    tmp->next = right;
    return;
}

void removeDuplicates(Node *h)
{
    if (!h)
        return;
    Node *prev = h, *curr = h->next;
    while (curr)
    {
        // I did a mistake by comparing just the nodes
        // like this : if(curr == prev) which never went true
        // because curr and prev point to different nodes
        // although they might have same data but their
        // links will never be the same
        if (curr->data == prev->data)
        {
            delNode(prev);
            curr = prev->next;
            continue;
        }
        // else:-
        prev = curr;
        curr = curr->next;
    }
    return;
}

int main(void)
{

    Node *h;
    input(&h);

    cout << "The Original Linked-List :-\n\n";
    printList(h);

    removeDuplicates(h);

    cout << "\n\nThe New(Modified) Linked-List :-\n\n";
    printList(h);

    freeList(&h);

    return 0;
}