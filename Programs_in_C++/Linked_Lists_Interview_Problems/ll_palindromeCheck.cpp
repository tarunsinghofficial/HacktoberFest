#include <iostream>
#include <stdlib.h>
#include <unordered_map>
#include <stack>
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

Node *revList2(Node *head)
{
    Node *prev = nullptr, *right = nullptr;
    while (head)
    {
        // preserving the right side
        right = head->next;
        // changing(reversing) the link
        head->next = prev;
        // propagating the pointers
        prev = head;
        head = right;
    }
    return prev;
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

Node *copyList(Node *head)
{
    if (!head)
        return nullptr;
    Node *ans = new Node(head->data);
    head = head->next;
    Node *cpy = ans; // this is a copy of head
    while (head)
    {
        ans->next = new Node(head->data);
        ans = ans->next;
        head = head->next;
    }
    ans->next = nullptr;
    // now ans points to tail of this ll
    ans = cpy;
    // now ans points to head of the ll
    cpy = nullptr; // task of cpy is over, hence make it point to null
    return ans;
}

bool isSame(Node *n1, Node *n2)
{
    while (n1 && n2)
    {
        if (n1->data != n2->data)
            return false;
        n1 = n1->next;
        n2 = n2->next;
    }
    return true;
}

bool isPalin(Node *head)
{
    Node *rev = nullptr, *it = head, *tmp = nullptr;
    while (it != nullptr)
    {
        if (rev == nullptr)
        {
            rev = new Node(it->data);
            tmp = rev; // copy of head
        }
        else
        {
            rev->next = new Node(it->data);
            rev = rev->next;
        }
        it = it->next;
    }
    if (rev != nullptr)
        rev->next = nullptr;
    rev = tmp; // restoring the head

    revList(&rev);

    if (isSame(head, rev))
        return true;
    // else:-
    return false;
}

bool isPalin2(Node *head)
{

    Node *cpy = copyList(head);
    Node *rev = revList2(cpy);

    // cout << "\n\n-----The reversed list-------------\n\n";
    // printList(rev);

    if (isSame(head, rev))
        return true;
    // else:-
    return false;
}

bool isPalin3(Node *head)
{
    int len = lenList(head);
    Node *it = head;
    for (int i = 1; i <= (len + 1) / 2 - 1; i++)
    {
        it = it->next;
    }
    // now if it is allowed to modify
    // the given linked list, then I'll do this :-
    // (else if it's not allowed, then I'll follow
    // the function : isPalin4())

    it = it->next; // it is now the head of the right half of LL

    cout << "\n\nRight half :- ";
    printList(it);

    Node *tmp = head;
    for (int i = 1; i <= len / 2 - 1; i++)
    {
        tmp = tmp->next;
    }
    if (len & 1)
    {
        Node *temp = tmp->next;
        tmp->next = nullptr;
        temp->next = nullptr;
        free(temp);
    }
    else
        tmp->next = nullptr;

    // reversing the right half
    it = revList2(it);

    cout << "\n\nAfter reversing, right side : ";
    printList(it);
    cout << "and\n\nLeft side : ";
    printList(head);

    if (isSame(head, it))
        return true;
    // else:-
    return false;
}

bool isPalin4(Node *head)
{
    stack<int> stk;
    int len = lenList(head);
    Node *it = head;
    stk.push(it->data);
    for (int i = 1; i <= (len + 1) / 2 - 1; i++)
    {
        it = it->next;
        stk.push(it->data);
    }
    cout << "\n\nit :- ";
    printList(it);
    cout << "\n\nstack size = " << stk.size();

    while (it != nullptr)
    {
        int top = stk.top();
        cout << "\ntop = " << top;
        if (it->data == top)
            stk.pop();
        else
            return false;
        it = it->next;
    }
    return true;
}

bool isPalin5(Node *head)
{
    int len = lenList(head);
    int center_idx = len / 2 + 1;
    unordered_map<int, int> mpp;
    Node *cpy = head;
    for (int idx = 1; idx <= (len / 2 + len / 2 + 1); idx++)
    {
        // filling phase :-
        if (idx < center_idx)
        {
            mpp[center_idx - idx] = cpy->data; // distance -> value mapping
        }
        else if (idx == center_idx && len & 1 == 0)
            continue; // to prevent an extra and unnecessary jump of the node pointer cpy
        // checking phase :-
        else if (idx > center_idx)
        {
            int dist = idx - center_idx;
            if (mpp[dist] != cpy->data)
                return false; // if values equidistant from the center don't match
        }
        cpy = cpy->next;
    }
    mpp.clear();
    return true;
}

int main(void)
{

    Node *h;
    input(&h);

    cout << "The Original Linked-List :-\n\n";
    printList(h);

    if (isPalin5(h))
        cout << "\n\nIt's a palindrome.";
    else
        cout << "\n\nNo. It's not a palindrome.";

    freeList(&h);

    return 0;
}