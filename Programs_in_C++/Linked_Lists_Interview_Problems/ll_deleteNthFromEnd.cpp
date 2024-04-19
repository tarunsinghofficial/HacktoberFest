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

void delFromEndOfList(Node *head, int n)
{
    int len = lenList(head);
    int start_pos = 1, target_pos = len - n;
    while (true)
    {
        if (start_pos == target_pos)
            break;
        head = head->next;
        start_pos++;
    }
    Node *ref = head->next->next;
    head->next->next = nullptr;
    free(head->next);
    head->next = ref;
    return;
}

int delFromEndOfList2(Node *head, int n)
{
    int len = lenList(head);
    int start_pos = 1, target_pos = len - n;
    while (true)
    {
        if (start_pos == target_pos)
            break;
        head = head->next;
        start_pos++;
    }
    Node *ref = head->next->next;
    head->next->next = nullptr;
    int val = head->next->data;
    free(head->next);
    head->next = ref;
    return val;
}

int delFromEndOfList3(Node *head, int n)
{
    revList(&head);
    // now, head is the new head of the ll after reversing int
    Node *ptr = head;
    int flag = 0;
    if (n == 1)
    {
        flag = 1;
        Node *tmp = new Node(-1);
        tmp->next = ptr;
        ptr = tmp;
        n++;
    }
    for (int i = 1; i <= n - 2; i++)
        ptr = ptr->next;
    Node *ref = ptr->next->next;
    ptr->next->next = nullptr;
    int data = ptr->next->data;
    free(ptr->next);
    ptr->next = ref;
    if (flag == 1)
    {
        head = ref;
        free(ptr);
    }
    revList(&head);
    // printList(head);
    return data;
}

int delFromEndOfList4(Node **head, int n)
{
    revList(&(*head));
    // now, head is the new head of the ll after reversing int
    Node *ptr = *head;
    int flag = 0;
    if (n == 1)
    {
        flag = 1;
        Node *tmp = new Node(-1);
        tmp->next = ptr;
        ptr = tmp;
        n++;
    }
    for (int i = 1; i <= n - 2; i++)
        ptr = ptr->next;
    Node *ref = ptr->next->next;
    ptr->next->next = nullptr;
    int data = ptr->next->data;
    free(ptr->next);
    ptr->next = ref;
    if (flag == 1)
    {
        *head = ref;
        free(ptr);
    }
    revList(&(*head));
    // printList(*head);
    // cout<<"\n\n";
    return data;
}

//-----------------------

pair<Node *, int> delFromEndOfList5(Node *head, int n)
{
    revList(&head);
    // now, head is the new head of the ll after reversing int
    Node *ptr = head;
    int flag = 0;
    if (n == 1)
    {
        flag = 1;
        Node *tmp = new Node(-1);
        tmp->next = ptr;
        ptr = tmp;
        n++;
    }
    for (int i = 1; i <= n - 2; i++)
        ptr = ptr->next;
    Node *ref = ptr->next->next;
    ptr->next->next = nullptr;
    int data = ptr->next->data;
    free(ptr->next);
    ptr->next = ref;
    if (flag == 1)
    {
        head = ref;
        free(ptr);
    }
    cout << "\n\nHead : ";
    printList(head);
    revList(&head);
    // printList(head);
    // cout<<"\n\n";
    return make_pair(head, data);
}

//----------------------------

Node *delFromEndOfList6(Node *head, int n)
{
    revList(&head);
    // now, head is the new head of the ll after reversing int
    Node *ptr = head;
    int flag = 0;
    if (n == 1)
    {
        flag = 1;
        Node *tmp = new Node(-1);
        tmp->next = ptr;
        ptr = tmp;
        n++;
    }
    for (int i = 1; i <= n - 2; i++)
        ptr = ptr->next;
    Node *ref = ptr->next->next;
    ptr->next->next = nullptr;
    free(ptr->next);
    ptr->next = ref;
    if (flag == 1)
    {
        head = ref;
        free(ptr);
    }
    revList(&head);
    // printList(head);
    return head;
}

int main(void)
{

    Node *h;
    input(&h);

    cout << "The Original Linked-List :-\n\n";
    printList(h);

    int n;
    cin >> n;
    // delFromEndOfList(h, n);
    // int deletedData = delFromEndOfList2(h, n);

    /* This helps when the head is to be deleted and
        we want to keep track of the 2nd note as a safety measure
        else head gets lost (freed) and we get null
        because we haven't passed head by it's address -> so in the function
        the head points to desired location only locally -> not outside of it
    */
    // Node *safety;
    // if(n == lenList(h)) safety = h->next;
    // else safety = h;
    // int deletedData = delFromEndOfList3(h, n);
    // h = safety;

    // 4th method :-
    // int deletedData = delFromEndOfList4(&h, n);

    /* I did this before and it deleted two elements -> because
       I called the function twice -> that cause repeated deletion
       thus gave wrong answer :-

        h = (delFromEndOfList5(h, n)).first;
        int deletedData = (delFromEndOfList5(h, n)).second;
     */
    pair<Node *, int> p = delFromEndOfList5(h, n);
    h = p.first;
    int deletedData = p.second;

    // int deletedData = 0;
    // int len = lenList(h);
    // Node *tmp = h;

    // for(int i=0; i<len-n; i++){
    //     tmp = tmp->next;
    // }
    // deletedData = tmp->data;

    // h = delFromEndOfList6(h, n);

    cout << "\n\nThe New(Modified) Linked-List :-\n\n";
    printList(h);

    cout << "\n\nDeleted Data : " << deletedData;

    freeList(&h);

    return 0;
}