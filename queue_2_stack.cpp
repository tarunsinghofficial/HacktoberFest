#include <iostream>
#include <stack>

using namespace std;

class QueueUsingTwoStacks {
private:
    stack<int> stackEnqueue;
    stack<int> stackDequeue;

public:
    // Function to enqueue an element
    void enqueue(int value) {
        stackEnqueue.push(value);
    }

    // Function to dequeue an element
    int dequeue() {
        // If both stacks are empty, the queue is empty
        if (stackEnqueue.empty() && stackDequeue.empty()) {
            cout << "Queue is empty." << endl;
            return -1; // Return a default value to indicate an empty queue
        }

        // If the dequeue stack is empty, transfer elements from enqueue stack
        if (stackDequeue.empty()) {
            while (!stackEnqueue.empty()) {
                stackDequeue.push(stackEnqueue.top());
                stackEnqueue.pop();
            }
        }

        // Pop and return the front element from dequeue stack
        int front = stackDequeue.top();
        stackDequeue.pop();
        return front;
    }

    // Function to check if the queue is empty
    bool isEmpty() {
        return stackEnqueue.empty() && stackDequeue.empty();
    }
};

int main() {
    QueueUsingTwoStacks myQueue;

    myQueue.enqueue(1);
    myQueue.enqueue(2);
    myQueue.enqueue(3);

    cout << "Dequeue: " << myQueue.dequeue() << endl;
    cout << "Dequeue: " << myQueue.dequeue() << endl;

    myQueue.enqueue(4);
    myQueue.enqueue(5);

    cout << "Dequeue: " << myQueue.dequeue() << endl;
    cout << "Dequeue: " << myQueue.dequeue() << endl;
    cout << "Dequeue: " << myQueue.dequeue() << endl;

    return 0;
}
