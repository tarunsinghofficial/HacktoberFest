// 🚀 LeetCode Problem :Merge Two Sorted Lists
// Language: C++
// Part of Hacktoberfest 2025 Contribution

#include <bits/stdc++.h>
using namespace std;

/*
🧠 Approach:
- We are given two sorted linked lists.
- Merge them into one sorted linked list.
- Use a dummy node to simplify merging.
- Traverse both lists and attach the smaller node each time.
- At the end, attach any remaining nodes from either list.

⌛ Time Complexity: O(n + m)  // n and m are lengths of lists
💾 Space Complexity: O(1)    // only pointers used
*/

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// Function to merge two sorted linked lists
ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    ListNode* dummy = new ListNode(0); // dummy head
    ListNode* tail = dummy;

    while (l1 && l2) {
        if (l1->val < l2->val) {
            tail->next = l1;
            l1 = l1->next;
        } else {
            tail->next = l2;
            l2 = l2->next;
        }
        tail = tail->next;
    }

    // attach remaining nodes
    tail->next = l1 ? l1 : l2;

    return dummy->next; // skip dummy head
}

// 🎯 Helper function to print linked list
void printList(ListNode* head) {
    while (head) {
        cout << head->val;
        if (head->next) cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

// 🎯 Driver Code
int main() {
    // Example: l1 = [1,2,4], l2 = [1,3,4]
    ListNode* l1 = new ListNode(1);
    l1->next = new ListNode(2);
    l1->next->next = new ListNode(4);

    ListNode* l2 = new ListNode(1);
    l2->next = new ListNode(3);
    l2->next->next = new ListNode(4);

    cout << "List 1: "; printList(l1);
    cout << "List 2: "; printList(l2);

    ListNode* merged = mergeTwoLists(l1, l2);
    cout << "Merged List: "; printList(merged);

    return 0;
}

/*
🧩 Sample Output:
List 1: 1 -> 2 -> 4
List 2: 1 -> 3 -> 4
Merged List: 1 -> 1 -> 2 -> 3 -> 4 -> 4
*/
