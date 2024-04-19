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

Node *input()
{
    int n;
    cin >> n;
    Node *head, *cpyHead;
    int val;
    for (int i = 0; i < n; i++)
    {
        cin >> val;
        if (i == 0)
        {
            head = new Node(val);
            cpyHead = head; // storing the head value
        }
        else
        {
            head->next = new Node(val);
            head = head->next;
        }
    }
    return cpyHead;
}

void printList(Node *ptr)
{
    while (ptr)
    {
        cout << ptr->data << " --> ";
        ptr = ptr->next;
    }
    cout << "NULL";
    return;
}

Node *merge(Node *left, Node *right)
{
    Node *ans = nullptr, *ans_head;

    while (left && right)
    {
        int l = left->data, r = right->data;
        if (l <= r)
        {
            if (!ans)
            {
                ans = new Node(l);
                ans_head = ans;
            }
            else
            {
                ans->next = new Node(l);
                ans = ans->next;
            }
            left = left->next;
        }
        else
        {
            if (!ans)
            {
                ans = new Node(r);
                ans_head = ans;
            }
            else
            {
                ans->next = new Node(r);
                ans = ans->next;
            }
            right = right->next;
        }
    }

    while (left)
    {
        if (!ans)
        {
            ans = new Node(left->data);
            ans_head = ans;
        }
        else
        {
            ans->next = new Node(left->data);
            ans = ans->next;
        }
        left = left->next;
    }
    while (right)
    {
        if (!ans)
        {
            ans = new Node(right->data);
            ans_head = ans;
        }
        else
        {
            ans->next = new Node(right->data);
            ans = ans->next;
        }
        right = right->next;
    }

    return ans_head;
}

Node *mergeSort(Node *head)
{
    // create left and right fragments
    // call mergeSort() with each fragment one after another
    // merge the sorted lists obtained from these two func calls
    // return head of the merged list

    if (!head || !head->next)
        return head;
    // finding centre of ll
    Node *s = head, *f = head;
    while (f->next)
    {
        f = f->next->next;
        if (!f)
            break;
        s = s->next;
    }
    // creating the right-side fragment
    Node *right_head = s->next;
    s->next = nullptr;

    head = merge(mergeSort(head), mergeSort(right_head));
    // note that the right argument will be evaluated first, and then the left argument
    // Node *first = mergeSort(head);
    // Node *second = mergeSort(right_head);
    // head = merge(first, second);
    return head;
}

int main(void)
{
    Node *head = input();
    head = mergeSort(head);
    printList(head);
    return 0;
}