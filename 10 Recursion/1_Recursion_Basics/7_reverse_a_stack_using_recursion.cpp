#include<bits/stdc++.h>
using namespace std;



class Solution {
public:
    void insertAtBottom(stack<int>& st, int x) {
        if (st.empty()) {
            st.push(x);
            return;
        }
        int temp = st.top();
        st.pop();
        insertAtBottom(st, x);
        st.push(temp);
    }

    void reverseStack(stack<int> &st) {
        if (st.empty()) {
            return;
        }
        int temp = st.top();
        st.pop();
        reverseStack(st);
        insertAtBottom(st, temp);
    }
};



int main() {
    Solution obj;
    stack<int> st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);
    obj.reverseStack(st);
    while (!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }
    return 0;
}



// Time Complexity: O(N²)
// Space Complexity: O(N)