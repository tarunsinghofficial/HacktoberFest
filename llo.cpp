#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int roll;
    string name;
    int sem, rank;
    Node *next;
    Node()
    {
    }
    Node(int data, string name1, int sem1, int rank1)
    {
        roll = data;
        name = name1;
        sem = sem1;
        rank = rank1;
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
    void insert(int roll2, string name2, int sem2, int rank2)
    {
        Node *new_node = new Node(roll2, name2, sem2, rank2);
        if (head == NULL)
        {
            head = new_node;
            return;
        }
        Node *temp = head;
        if (temp->rank > rank2)
        {
            new_node->next = head;
            head = new_node;
        }
        else
        {
            while (temp->next != NULL && temp->next->rank < rank2)
                temp = temp->next;
            new_node->next = temp->next;
            temp->next = new_node;
        }
    }
    void query()
    {
        Node *temp = head;
        while (temp != NULL)
        {
            cout << "Rank:" << temp->rank << '\t' << "Name:" << temp->name << '\t' << "Roll No:" << temp->roll << '\t' << "Sem:" << temp->sem << endl;
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
    void delk(Node *&head, int rank4)
    {
        if (head == NULL)
        {
            cout << "Empty list\n";
            return;
        }
        Node *prev = head;
        if (prev->rank == rank4)
        {
            Node *temp = head;
            head = head->next;
            free(temp);
            return;
        }
        while (prev->next->rank != rank4)
        {
            prev = prev->next;
        }
        Node *temp = prev->next;
        prev->next = prev->next->next;
        free(temp);
    }
    void updt(Node *head, int roll3, string name3, int sem3, int rank3)
    {
        if (head == NULL)
        {
            cout << "Empty list\n";
            return;
        }
        Node *temp = head;
        int cur = 0;
        while (temp->rank != rank3)
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
    int sem, roll, pos, rank;
    string name;
    cout << "Menu\n1 for insertion\n2 for deletion\n3 for query\n4 for updation\n5 for exit\n ";

    while (1)
    {
        cout << "Enter your choice\n";
        cin >> ch;

        if (ch == 1)
        {
            cout << "Enter the elements you want to insert(roll number,name,semester and rank)\n";
            cin >> roll >> name >> sem >> rank;
            ll1.insert(roll, name, sem, rank);
        }
        else if (ch == 2)
        {
            cout << "Enter the rank\n";
            cin >> rank;
            ll1.delk(ll1.head, rank);
        }
        else if (ch == 3)
        {
            ll1.query();
        }
        else if (ch == 4)
        {
            cout << "Enter the rank you want to update\n";
            cin >> rank;
            cout << "Enter the elements you want to insert(Roll number,name,semester)\n";
            cin >> roll >> name >> sem;
            ll1.updt(ll1.head, roll, name, sem, rank);
        }
        else
            break;
    }

    return 0;
}