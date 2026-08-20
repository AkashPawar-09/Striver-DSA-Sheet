#include <bits/stdc++.h>
using namespace std;


class MyStack {
    queue<int> q;

public:
    MyStack() {
        // IT'S EMPTY !!!
    }

    void push(int x) {
        q.push(x);
        int n = q.size();

        for (int i = 0; i < n - 1; i++) {
            q.push(q.front());
            q.pop();
        }
    }

    int pop() {
        int x = q.front();
        q.pop();
        return x;
    }

    int top() {
        return q.front();
    }

    bool empty() {
        return q.empty();
    }
};




int main() {
    MyStack st;

    st.push(10);
    st.push(20);
    st.push(30);

    cout << "Top: " << st.top() << endl;
    cout << "Pop: " << st.pop() << endl;
    cout << "Top: " << st.top() << endl;
    cout << "Pop: " << st.pop() << endl;
    cout << "Top: " << st.top() << endl;

    cout << "Empty: " << (st.empty() ? "Yes" : "No") << endl;

    return 0;
}


// Time Complexity : O(1)  FOR ALL OPERATIONS (except q.push = O(N) )
// Space Complexity : O(N)



/* --------------------------------------------------------------------------------------------------------------------

Example: push(1), push(2), push(3)

_____________________________________________________________________
| Step | Operation | q.push(x) | n | Loop Action | Queue After Step |
|------|-----------|-----------|---|-------------|------------------|
| 1    | push(1)   | [1]       | 1 | No loop     | [1]              |
| 2    | push(2)   | [1,2]     | 2 | Move 1      | [2,1]            |
| 3    | push(3)   | [2,1,3]   | 3 | Move 2,1    | [3,2,1]          |


Final Queue:
[3,2,1]


Stack view:
Top → 3
      2
      1
       
--------------------------------------------------------------------------------------------------------------------  */