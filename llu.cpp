#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int roll;
    string name;
    int sem;
    Node *next;
    Node()
    {
    }
    Node(int data, string name1, int sem1)
    {
        roll = data;
        name = name1;
        sem = sem1;
        next = NULL;
    }
};
class linkedlist
{
public:
    Node *head;
    linkedlist()
    {
        head = NULL;
    }
    void insert(int roll2, string name2, int sem2)
    {
        Node *new_node = new Node(roll2, name2, sem2);
        if (head == NULL)
        {
            head = new_node;
            return;
        }
        Node *temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = new_node;
    }
    void query()
    {
        Node *temp = head;
        while (temp != NULL)
        {
            cout << "Name:" << temp->name << '\t' << "Roll No:" << temp->roll << '\t' << "Sem:" << temp->sem << endl;
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
    void delk(Node *&head, int pos)
    {
        if (head == NULL)
        {
            cout << "Empty list\n";
            return;
        }
        if (pos == 0)
        {
            Node *temp = head;
            head = head->next;
            free(temp);
            return;
        }
        int cur = 0;
        Node *prev = head;
        while (cur != pos - 1)
        {
            prev = prev->next;
            cur++;
        }
        Node *temp = prev->next;
        prev->next = prev->next->next;
        free(temp);
    }
    void updt(Node *head, int roll3, string name3, int sem3, int pos)
    {
        if (head == NULL)
        {
            cout << "Empty list\n";
            return;
        }
        Node *temp = head;
        int cur = 0;
        while (cur != pos - 1)
        {
            temp = temp->next;
            cur++;
        }
        temp->roll = roll3;
        temp->name = name3;
        temp->sem = sem3;
    }
};
int main()
{
    linkedlist ll1;
    int ch;
    int sem, roll, pos;
    string name;
    cout << "Menu\n1 for insertion\n2 for deletion\n3 for query\n4 for updation\n5 for exit\n ";

    while (1)
    {
        cout << "Enter your choice\n";
        cin >> ch;

        if (ch == 1)
        {
            cout << "Enter the elements you want to insert(Roll number.name and semester)\n";
            cin >> roll >> name >> sem;
            ll1.insert(roll, name, sem);
        }
        else if (ch == 2)
        {
            cout << "Enter the position\n";
            cin >> pos;
            ll1.delk(ll1.head, pos - 1);
        }
        else if (ch == 3)
        {
            ll1.query();
        }
        else if (ch == 4)
        {
            cout << "Enter the position\n";
            cin >> pos;
            cout << "Enter the elements you want to insert(Roll number.name and semester)\n";
            cin >> roll >> name >> sem;
            ll1.updt(ll1.head, roll, name, sem, pos);
        }
        else
            break;
    }

    return 0;
}