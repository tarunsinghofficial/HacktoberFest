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

    // new head
    *head = prev;

    return;
}

Node *add(Node *h1, Node *h2)
{
    Node *ans = nullptr, *ans_head = nullptr;
    int sum, carry = 0, count = 0;
    while (h1 != nullptr && h2 != nullptr)
    {
        count++;
        sum = (h1->data + h2->data + carry) % 10;
        carry = (h1->data + h2->data) / 10;
        if (count == 1)
        {
            ans = new Node(sum);
            ans_head = ans;

            h1 = h1->next;
            h2 = h2->next;

            continue;
        }
        // else:-
        ans->next = new Node(sum);
        ans = ans->next;

        h1 = h1->next;
        h2 = h2->next;
    }
    while (h1 != nullptr)
    {
        int value = h1->data;
        if (carry > 0)
        {
            value += carry;
            carry = 0;
        }
        sum = (value + carry) % 10;
        carry = value / 10;
        if (count == 0)
        {
            ans = new Node(sum);
            ans_head = ans;
            h1 = h1->next;
            continue;
        }
        ans->next = new Node(sum);
        ans = ans->next;

        h1 = h1->next;
    }
    while (h2 != nullptr)
    {
        int value = h2->data;
        if (carry > 0)
        {
            value += carry;
            carry = 0;
        }
        sum = (value + carry) % 10;
        carry = value / 10;
        if (count == 0)
        {
            ans = new Node(sum);
            ans_head = ans;

            h2 = h2->next;

            continue;
        }
        ans->next = new Node(sum);
        ans = ans->next;

        h2 = h2->next;
    }
    if (carry > 0)
    {
        ans->next = new Node(carry);
        ans = ans->next;
    }
    if (ans != nullptr)
        ans->next = nullptr;
    return ans_head;
}

Node *subtract(Node *h1, Node *h2)
{
    Node *ans = nullptr, *ans_head = nullptr;
    int difference, borrow = 0, num, count = 0;

    while (h1 != nullptr && h2 != nullptr)
    {
        count++;
        num = h1->data - (h2->data + borrow);
        if (num >= 0)
        {
            difference = num;
            borrow = 0;
        }
        else
        {
            num += 10;
            difference = num;
            borrow = 1;
        }
        if (count == 1)
        {
            ans = new Node(difference);
            ans_head = ans;

            h1 = h1->next;
            h2 = h2->next;

            continue;
        }
        // else:-
        ans->next = new Node(difference);
        ans = ans->next;

        h1 = h1->next;
        h2 = h2->next;
    }
    while (h1 != nullptr)
    {
        int value = h1->data;
        num = value - borrow;
        if (num >= 0)
        {
            difference = num;
            borrow = 0;
        }
        else
        {
            difference = num + 10;
            borrow = 1;
        }
        if (count == 0)
        {
            ans = new Node(difference);
            ans_head = ans;
            h1 = h1->next;
            count++;
            continue;
        }
        ans->next = new Node(difference);
        ans = ans->next;

        h1 = h1->next;
    }
    if (ans != nullptr)
        ans->next = nullptr;
    return ans_head;
}

void freeList(Node **head)
{
    free(*head);
    *head = nullptr;
    return;
}

void createLoop(Node *head)
{
    int pos;
    cin >> pos;
    Node *tail = head;
    if (tail == nullptr)
        return;
    while (tail->next != nullptr)
        tail = tail->next;
    Node *ele = head;
    for (int i = 0; i < pos - 1; i++)
        ele = ele->next;
    tail->next = ele;
    return;
}

bool isCycle(Node *head)
{
    Node *s = head, *f = head;
    while (true)
    {
        if (!s)
            break;
        s = s->next;
        if (!f || !f->next)
            break;
        f = f->next->next;
        if (s == f)
            return true;
    }
    return false;
}

int lenCycle(Node *he)
{
    int len = 0;
    Node *s = he, *f = he;
    while (true)
    {
        s = s->next;
        f = f->next->next;
        if (s == f)
            break;
    }
    s = s->next;
    f = f->next->next;
    len = 1;
    while (s != f)
    {
        s = s->next;
        f = f->next->next;
        len++;
    }
    return len;
}

pair<int, int> startOfCycle(Node *head)
{
    Node *slow = head, *fast = head;
    slow = slow->next;
    fast = fast->next->next;
    while (slow != fast)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    slow = head;
    int counter = 1;
    while (slow != fast)
    {
        slow = slow->next;
        fast = fast->next;
        counter++;
    }
    return make_pair(counter, slow->data);
}

int main(void)
{

    Node *h;
    input(&h);

    createLoop(h);

    bool cycle = isCycle(h);
    if (cycle)
    {
        cout << "Cycle detected.\n";
        int len = lenCycle(h);
        cout << "Length of the Cycle = " << len;
        pair<int, int> start = startOfCycle(h);
        cout << "\nCycle starts at position : " << start.first << " and \nThe node value is : " << start.second;
    }
    else
        cout << "No cycle detected.";

    freeList(&h);

    return 0;
}