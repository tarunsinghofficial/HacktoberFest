#include <iostream>
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

pair<Node *, Node *> revList(Node *head)
{
    Node *curr = head, *prev = nullptr, *right;
    while (curr)
    {
        right = curr->next;
        curr->next = prev;
        prev = curr;
        curr = right;
    }
    return make_pair(prev, head);
}
Node *revKrec(Node *h, Node *prev, int k)
{
    Node *it = h, *right;
    int counter = 0;
    while (it)
    {
        counter++;
        if (counter % k == 0)
        {
            right = it->next;
            it->next = nullptr;
            pair<Node *, Node *> p = revList(h); // try just with make_pair(x, y) = func();
            h = p.first;
            it = p.second;
            // make_pair(h, it) = revList(h); // tried and found that this doesn't work
            break;
        }
        else
        {
            it = it->next;
        }
    }
    if (counter < k)
        return h; // edge case : when end of ll is reached
    if (prev)
        prev->next = h;
    it->next = revKrec(right, it, k);
    return h;
}
Node *revK(Node *h, int k)
{
    Node *f = h, *l = h, *r, *prev;
    int counter = 0;
    while (l)
    {
        counter++;
        if (counter % k == 0)
        {
            r = l->next;
            l->next = nullptr;
            pair<Node *, Node *> p = revList(f);
            if (counter == k)
                h = p.first;
            else
                prev->next = p.first;
            p.second->next = r;
            prev = f; // prev = l;
            f = r;
            l = r;
        }
        else
            l = l->next;
    }
    return h;
}

int main(void)
{
    Node *head = input();
    int k;
    cin >> k;
    // head = revK(head, k);
    Node *prev = nullptr;
    head = revKrec(head, prev, k);
    printList(head);
    return 0;
}