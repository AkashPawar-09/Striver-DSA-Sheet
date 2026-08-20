#include <bits/stdc++.h>
using namespace std;

class Stack {
    int arr[1000] ;
    int top ;

public:
    Stack() {
        top = -1 ;
    }

    void push(int x) {
        if(top==999) return ;
        arr[++top] = x;
    }

    int pop() {
        if (top == -1) return -1;
        return arr[top--];
    }

    int peek() {
        if (top == -1) return -1;
        return arr[top];
    }

    bool isEmpty() {
        return top == -1;
    }
};


int main() {
    Stack st;
    st.push(10);
    st.push(20);
    st.push(30);
    cout << st.peek() << endl;
    cout << st.pop() << endl;
    cout << st.peek() << endl;
    cout << (st.isEmpty() ? "Empty" : "Not Empty") << endl;
    return 0;
}


// Time Complexity : O(1)
// Space Complexity : O(N)