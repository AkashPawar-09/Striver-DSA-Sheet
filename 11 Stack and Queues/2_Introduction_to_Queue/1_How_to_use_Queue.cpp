#include <iostream>
#include <queue>       // STL queue container
using namespace std;

class MyQueue {
    queue<int> q;                      // underlying STL queue

public:
    void push(int x) {                 // enqueue: insert x at the rear
        q.push(x);                     // O(1)
    }

    int pop() {                        // dequeue: remove and return front element
        if (isEmpty()) {               // guard against underflow
            cout << "Queue is empty!\n";
            return -1;                 // sentinel for empty case
        }
        int val = q.front();           // fetch front value before removing
        q.pop();                       // remove it
        return val;                    // return removed value
    }

    int front() {                      // return front element without removing
        if (isEmpty()) {
            cout << "Queue is empty!\n";
            return -1;
        }
        return q.front();              // just read, no modification
    }

    int back() {                       // return rear element without removing
        if (isEmpty()) {
            cout << "Queue is empty!\n";
            return -1;
        }
        return q.back();               // just read, no modification
    }

    bool isEmpty() {                   // check if queue has no elements
        return q.empty();              // true if size == 0
    }

    int size() {                       // number of elements currently in queue
        return q.size();
    }
};




int main() {
    MyQueue q;                         // create queue object

    q.push(10);                        // queue: [10]
    q.push(20);                        // queue: [10,20]
    q.push(30);                        // queue: [10,20,30]

    cout << "Size: " << q.size() << "\n";          // expect 3
    cout << "Front: " << q.front() << "\n";         // expect 10
    cout << "Back: " << q.back() << "\n";            // expect 30

    cout << "Dequeued: " << q.pop() << "\n";         // expect 10, queue: [20,30]
    cout << "Front after pop: " << q.front() << "\n"; // expect 20

    cout << "isEmpty: " << (q.isEmpty() ? "true" : "false") << "\n"; // expect false
    cout << "Size: " << q.size() << "\n";            // expect 2

    return 0;
}



// Time Complexity : O(1)  FOR ALL OPERATIONS 
// Space Complexity : O(N)