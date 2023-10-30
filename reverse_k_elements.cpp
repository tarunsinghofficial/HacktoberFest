#include <iostream>
#include <queue>
#include <stack>
using namespace std;
void reverseUpToK(queue<int>& q, int k) {
    stack<int> s;
    
    // Push the first k elements into the stack
    for (int i = 0; i < k; ++i) {
        s.push(q.front());
        q.pop();
    }

    // Enqueue the elements from the stack
    while (!s.empty()) {
        q.push(s.top());
        s.pop();
    }

    // Move the remaining elements in the queue to the back
    for (int i = 0; i < q.size() - k; ++i) {
        q.push(q.front());
        q.pop();
    }
}

int main() {
    queue<int> q;
    for (int i = 1; i <= 5; ++i) {
        q.push(i);
    }

    cout << "Original queue: ";
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }

    for (int i = 1; i <= 5; ++i) {
        q.push(i);
    }

    int k = 3;
    reverseUpToK(q, k);

    cout << "\nReversed first " << k << " elements: ";
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }

    return 0;
}
