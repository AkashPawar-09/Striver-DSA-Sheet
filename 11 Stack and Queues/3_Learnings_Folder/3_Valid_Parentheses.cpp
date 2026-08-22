#include <bits/stdc++.h>
using namespace std;



class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        int n = s.size();

        for(int i = 0; i < n; i++) {

            if(s[i] == '(') st.push('(');

            else if(s[i] == ')') {
                if(st.empty()) return false;
                if(st.top() != '(') return false;
                st.pop();
            }

            else if(s[i] == '[') {
                st.push('[');
            }

            else if(s[i] == ']') {
                if(st.empty()) return false;
                if(st.top() != '[') return false;
                st.pop();
            }

            else if(s[i] == '{') st.push('{');

            else if(s[i] == '}') {
                if(st.empty()) return false;
                if(st.top() != '{') return false;
                st.pop();
            }
        }

        if(st.empty()) return true;
        return false;
    }
};



int main() {
    Solution obj;
    string s;
    cin >> s;
    if(obj.isValid(s)) cout << "true";
    else cout << "false";
    return 0;
}




// Time Complexity: O(N)
// Space Complexity: O(N)