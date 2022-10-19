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

void odd_even_rearrange(Node *p1, Node *even_ref, int counter)
{
    // cout << "\n-------------------\n";
    // cout << "P1 :- ";
    // printList(p1);
    // cout << "\n-------------------\n";
    if (!p1)
        return;
    if (counter & 1)
    {
        if (p1->next == nullptr || p1->next->next == nullptr)
        {
            Node *tmp = p1->next;
            p1->next = even_ref;
            odd_even_rearrange(tmp, even_ref, counter + 1);
            return;
        }
    }
    else
    {
        if (p1->next == nullptr || p1->next->next == nullptr)
        {
            Node *tmp = p1->next;
            p1->next = nullptr;
            odd_even_rearrange(tmp, even_ref, counter + 1);
            return;
        }
    }
    // else :-
    Node *p2 = p1->next; // storing 2nd
    if (p1->next)
        p1->next = p1->next->next; // joining 1st with 3rd
    odd_even_rearrange(p2, even_ref, counter + 1);
    return;
}

int main(void)
{

    Node *h;
    input(&h);

    cout << "The Original Linked-List :-\n\n";
    printList(h);

    if (h != nullptr && h->next != nullptr)
        odd_even_rearrange(h, h->next, 1);

    cout << "\n\nThe New(Modified) Linked-List :-\n\n";
    printList(h);

    freeList(&h);

    return 0;
}