#include<bits/stdc++.h>
using namespace std ;

class myQueue {
    int arr[1000];
    int front;                      // front = start 
    int rear;                       // rear = end
    int size;                       // size = size of arr

public:
    myQueue(int n) {
        size = n;
        front = 0;
        rear = 0;
    }

    bool isEmpty() {
        return front == rear;
    }

    bool isFull() {
        return rear == size;
    }

    void enqueue(int x) {
        if (isFull()) return;
        arr[rear++] = x;
    }

    int dequeue() {
        if (isEmpty()) return -1;
        return arr[front++];
    }

    int getFront() {
        if (isEmpty()) return -1;
        return arr[front];
    }

    int getRear() {
        if (isEmpty()) return -1;
        return arr[rear - 1];
    }
};



int main() {
    myQueue q(5);
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    cout << "Front: " << q.getFront() << endl;
    cout << "Rear: " << q.getRear() << endl;
    cout << "Dequeued: " << q.dequeue() << endl;
    cout << "Front: " << q.getFront() << endl;
    cout << "Rear: " << q.getRear() << endl;
    cout << "Is Empty: " << (q.isEmpty() ? "Yes" : "No") << endl;
    cout << "Is Full: " << (q.isFull() ? "Yes" : "No") << endl;
    return 0;
}


// Time Complexity : O(1)
// Space Complexity : O(N)