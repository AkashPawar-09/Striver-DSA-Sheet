#include<bits/stdc++.h>
using namespace std;

// In this recursive method , we pop all items and refiil it from smallest 
// if more small number is found , then pop all items and recall back





// Solution

class Solution {
public:
    void insert(stack<int>& s, int temp) {
        if (s.empty() || s.top() <= temp) {
            s.push(temp);
            return;
        }

        int val = s.top();
        s.pop();

        insert(s, temp);

        s.push(val);
    }

    void sortStack(stack<int> &st) {
        if (!st.empty()) {
            int temp = st.top();
            st.pop();

            sortStack(st);

            insert(st, temp);
        }
    }
};



int main() {
    Solution obj;
    stack<int> st;
    st.push(4);
    st.push(5);
    st.push(2);
    st.push(3);
    st.push(1);
    obj.sortStack(st);
    while (!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }
    return 0;
}


// Time Complexity: O(N²)
// Space Complexity: O(N)