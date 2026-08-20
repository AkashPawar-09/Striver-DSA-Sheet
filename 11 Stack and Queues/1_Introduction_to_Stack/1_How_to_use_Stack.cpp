#include <iostream>
#include <stack>       // STL stack container
using namespace std;

class MyStack {
    stack<int> st;                     // underlying STL stack

public:
    void push(int x) {                 // insert x on top
        st.push(x);                    // O(1)
    }

    int pop() {                        // remove and return top element
        if (isEmpty()) {               // guard against underflow
            cout << "Stack is empty!\n";
            return -1;                 // sentinel for empty case
        }
        int val = st.top();            // fetch top value before removing
        st.pop();                      // remove it
        return val;                    // return removed value
    }

    int top() {                        // peek: return top without removing
        if (isEmpty()) {
            cout << "Stack is empty!\n";
            return -1;
        }
        return st.top();               // just read, no modification
    }

    bool isEmpty() {                   // check if stack has no elements
        return st.empty();             // true if size == 0
    }

    int size() {                       // number of elements currently in stack
        return st.size();
    }
};




int main() {
    MyStack s;                         // create stack object

    s.push(10);                        // stack: [10]
    s.push(20);                        // stack: [10,20]
    s.push(30);                        // stack: [10,20,30]

    cout << "Size: " << s.size() << "\n";        // expect 3
    cout << "Top: " << s.top() << "\n";           // expect 30

    cout << "Popped: " << s.pop() << "\n";        // expect 30, stack: [10,20]
    cout << "Top after pop: " << s.top() << "\n"; // expect 20

    cout << "isEmpty: " << (s.isEmpty() ? "true" : "false") << "\n"; // expect false
    cout << "Size: " << s.size() << "\n";         // expect 2

    return 0;
}



// Time Complexity : O(1)  FOR ALL OPERATIONS 
// Space Complexity : O(N)