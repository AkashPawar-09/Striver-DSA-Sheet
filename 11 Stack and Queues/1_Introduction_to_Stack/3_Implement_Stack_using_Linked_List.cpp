#include <iostream>
using namespace std;


struct Node {                   // basic singly linked list node
    int data;                   // stores value
    Node* next;                 // pointer to next node

    Node(int val) {             // constructor to initialize node
        data = val;
        next = NULL;
    }
};



class myStack {
    Node* head;         // pointer to top of stack (head of linked list)
    int count;          // tracks number of elements for O(1) size()

public:
    myStack() {
        head = NULL;                    // stack starts empty
        count = 0;                      // no elements initially
    }

    bool isEmpty() {
        return head == NULL;            // stack is empty if head points to nothing
    }

    void push(int x) {
        Node* newNode = new Node(x);    // create new node with value x
        newNode->next = head;           // link new node to current top
        head = newNode;                 // new node becomes the top
        count++;                        // one more element added
    }

    void pop() {
        if (isEmpty()) return;          // nothing to remove, guard against underflow
        Node* temp = head;              // save current top to delete it
        head = head->next;              // move top pointer to next node
        delete temp;                    // free memory of old top
        count--;                        // one less element
    }

    int peek() {
        if (isEmpty()) return -1;       // sentinel value when stack is empty
        return head->data;              // return value at top without removing
    }

    int size() {
        return count;                   // O(1) lookup since count is maintained
    }
};




int main() {
    myStack s;

    s.push(10);
    s.push(20);
    s.push(30);

    cout << "Size: " << s.size() << "\n";
    cout << "Peek: " << s.peek() << "\n";

    s.pop();
    cout << "Peek after pop: " << s.peek() << "\n";
    cout << "isEmpty: " << (s.isEmpty() ? "true" : "false") << "\n";
    cout << "Size: " << s.size() << "\n";

    return 0;
}




// Time Complexity : O(1)
// Space Complexity : O(N)