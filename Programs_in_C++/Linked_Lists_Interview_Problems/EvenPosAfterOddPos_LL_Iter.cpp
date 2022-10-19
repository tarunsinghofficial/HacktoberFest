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
            // return;
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
            // return;
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

void odd_even_rearrange2(Node *head)
{
    Node *second = head->next;
    Node *current = second, *previous = head;

    // 1 2 3 4
    // 1 2 3 4 5

    int counter = 0;

    while (current)
    {
        counter++;

        // cout<<"\n\nCOUNTER == "<<counter;

        // Step-1
        if (current->next)
            previous->next = current->next; // 1->3, 2->4 (when len=even) // 1->3, 2->4, 3->5
        else
        {
            if (counter & 1)
                previous->next = second; // 3->2
            else
                previous->next = nullptr;
        }

        // cout<<"\n$$$$$\n";
        // printList(current);
        // cout<<endl;
        // printList(previous);
        // cout<<endl;
        // cout<<"\n$$$$$\n";

        // Step-2
        previous = current;      // 1, 2, 3, 4  // 1, 2, 3, 4, 5
        current = current->next; // 2, 3, 4, NULL  // 2, 3, 4, 5, NULL

        // cout<<"\n%%%%\n";
        // printList(current);
        // cout<<endl;
        // printList(previous);
        // cout<<endl;
        // cout<<"\n%%%%\n";
    }
    counter++; // length of the ll
    if (counter & 1)
        previous->next = second;
    return;
}

Node *even_odd_rearrange(Node *head)
{
    Node *dummy = new Node(-1);
    dummy->next = head;
    head = dummy;
    odd_even_rearrange2(head);
    Node *tmp = head;
    head = head->next;
    tmp->next = nullptr; // disconnecting the dummy node from the main linked list
    free(tmp);           // freeing the dummy node
    return head;
}

void even_odd_rearrange(Node **head)
{
    Node *dummy = new Node(-1);
    dummy->next = *head;
    *head = dummy;
    odd_even_rearrange2(*head);
    Node *tmp = *head;
    *head = (*head)->next;
    tmp->next = nullptr; // disconnecting the dummy node from the main linked list
    free(tmp);           // freeing the dummy node
    return;
}

Node *even_odd_rearrange2(Node *head)
{
    Node *second = head->next;
    Node *current = head, *next = second;

    // 1 2 3 4
    // 1 2 3 4 5
    int counter = 0;
    while (next)
    {
        counter++;
        // step-1 : reconnecting the current pointer with next alternative neighbour
        if (!next->next && !(counter & 1))
        {
            // this if is specially for odd-lengthed linked lists
            // AT THE LAST ELEMENT OF EVEN LIST
            current->next = head;
        }
        else
            current->next = next->next;
        // Result of stage-1 per iteration: 1->3, 2->4, 3->NULL  // 1->3, 2->4, 3->5, 4->1

        // step-2 : updating the pointer positions
        current = next;    // 1=>2, 2=>3, 3=>4  // 1=>2, 2=>3, 3=>4,
        next = next->next; // 2=>3, 3=>4, 4=>NULL  // 2=>3, 3=>4, 4=>5
    }
    counter++; // == length of the linked list
    // now current points to last
    if (!(counter & 1))
    {
        current->next = head;
    }
    return second;
}

void even_odd_rearrange2(Node **head)
{
    Node *second = (*head)->next;
    Node *current = *head, *next = second;
    // 1 2 3 4
    // 1 2 3 4 5
    int counter = 0;
    while (next)
    {
        counter++;
        // step-1 : reconnecting the current pointer with next alternative neighbour
        if (!next->next && !(counter & 1))
        {
            // this if is specially for odd-lengthed linked lists
            // AT THE LAST ELEMENT OF EVEN LIST
            current->next = *head;
        }
        else
            current->next = next->next;
        // Result of stage-1 per iteration: 1->3, 2->4, 3->NULL  // 1->3, 2->4, 3->5, 4->1

        // step-2 : updating the pointer positions
        current = next;    // 1=>2, 2=>3, 3=>4  // 1=>2, 2=>3, 3=>4,
        next = next->next; // 2=>3, 3=>4, 4=>NULL  // 2=>3, 3=>4, 4=>5
    }
    counter++; // == length of the linked list
    // now current points to last
    if (!(counter & 1))
    {
        current->next = *head;
    }

    *head = second;

    return;
}

int main(void)
{

    Node *h;
    input(&h);

    cout << "The Original Linked-List :-\n\n";
    printList(h);

    if (h != nullptr && h->next != nullptr)
        // odd_even_rearrange(h, h->next, 1);
        // odd_even_rearrange2(h);
        // h = even_odd_rearrange(h);
        // even_odd_rearrange(&h);
        // h = even_odd_rearrange2(h);
        even_odd_rearrange2(&h);

    cout << "\n\nThe New(Modified) Linked-List :-\n\n";
    printList(h);

    freeList(&h);

    return 0;
}