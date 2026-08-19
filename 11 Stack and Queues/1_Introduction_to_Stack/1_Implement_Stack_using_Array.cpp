#include <iostream>
using namespace std;

class StackArray {
    int* arr;
    int capacity;
    int top;

public:
    StackArray(int cap) {
        capacity = cap;
        arr = new int[capacity];
        top = -1; // empty stack
    }

    void push(int x) {
        if (top == capacity - 1) {
            cout << "Stack Overflow\n";
            return;
        }
        arr[++top] = x;
    }

    int pop() {
        if (isEmpty()) {
            cout << "Stack Underflow\n";
            return -1;
        }
        return arr[top--];
    }

    int peek() {
        if (isEmpty()) {
            cout << "Stack is empty\n";
            return -1;
        }
        return arr[top];
    }

    bool isEmpty() {
        return top == -1;
    }

    int size() {
        return top + 1;
    }

    ~StackArray() {
        delete[] arr;
    }
};

int main() {
    StackArray s(100);
    s.push(10);
    s.push(20);
    s.push(30);
    cout << s.pop() << endl;   // 30
    cout << s.peek() << endl;  // 20
    cout << s.size() << endl;  // 2
    return 0;
}