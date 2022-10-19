#include <iostream>
#include <unordered_map>
using namespace std;

class SplNode
{
public:
    int value;
    SplNode *next;
    SplNode *arbit;
};

SplNode *input()
{
    int n, tmp;
    cin >> n;
    SplNode *head, *prev;

    unordered_map<int, SplNode *> mpp;

    for (int i = 0; i < n; i++)
    {
        cin >> tmp;
        SplNode *temp = new SplNode();
        temp->value = tmp;
        if (i == 0)
        {
            head = temp;
            prev = head;
        }
        else
        {
            prev->next = temp;
            prev = prev->next;
        }
        mpp[tmp] = prev;
    }
    // N^2 process but constant space :-
    // SplNode *curr = head;
    // for(int i=0; i<n; i++){
    //     cin>>tmp;
    //     SplNode *cpy = head;
    //     while(cpy->value != tmp){
    //         cpy = cpy->next;
    //     }
    //     curr->arbit = cpy;
    //     curr = curr->next;
    // }

    SplNode *it = head;
    for (int i = 0; i < n; i++)
    {
        cin >> tmp;
        it->arbit = mpp[tmp];
        it = it->next;
    }

    return head;
}

void printList(SplNode *head)
{
    while (head)
    {
        cout << head->value << '(' << head->arbit->value << ')' << " --> ";
        head = head->next;
    }
    cout << "NULL";
    return;
}

SplNode *copyLL(SplNode *head)
{
    SplNode *it = head, *ans = nullptr, *ans_head;
    while (it)
    {
        if (!ans)
        {
            ans = new SplNode();
            ans_head = ans;
        }
        else
        {
            ans->next = new SplNode();
            ans = ans->next;
        }
        ans->value = it->value;
        ans->arbit = it->arbit;
        it = it->next;
    }
    return ans_head;
}

int main(void)
{

    SplNode *head = input();

    cout << "Given LL :- ";
    printList(head);
    cout << "\n\n";

    SplNode *copied = copyLL(head);

    cout << "Clone LL :- ";
    printList(copied);
    cout << "\n\n";

    return 0;
}