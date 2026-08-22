#include <bits/stdc++.h>
using namespace std;



class Solution {
public:
    int priority(char c) {                                  // returns precedence rank of operator c
        if(c == '^') return 3;                              // exponentiation has highest priority
        if(c == '*' || c == '/') return 2;                  // multiplication/division next
        if(c == '+' || c == '-') return 1;                  // addition/subtraction lowest
        return 0;                                           // non-operator (e.g. parenthesis) gets 0
    }
    
    string infixToPostfix(string& s) {
        stack<char> st;                                     // stack to hold operators and '('
        string ans;                                         // builds the resulting postfix expression

        for(int i = 0; i < s.size(); i++) {                 // scan infix expression left to right
            if(isalnum(s[i])) {                             // if current char is operand (letter/digit) alphanumeric character
                ans = ans + s[i];                           // append it directly to output
            }
            else if(s[i] == '(') {                          // if opening bracket
                st.push(s[i]);                              // push it onto stack to mark scope
            }
            else if(s[i] == ')') {                          // if closing bracket
                while(!st.empty() && st.top() != '(') {     // pop and output until '(' is found
                    ans = ans + st.top();                   // append popped operator to output
                    st.pop();                               // remove it from stack
                }
                st.pop();                                   // discard the matching '(' itself
            }
            else {                                          // current char is an operator
                while ( !st.empty() && st.top() != '(' &&   // pop while stack has operator (not '(')
                ( priority(st.top()) > priority(s[i]) ||    // and top has strictly higher priority
                ( priority(st.top()) == priority(s[i]) &&   // or equal priority
                s[i] != '^') ) )                            // but current operator is not right-associative '^'
                {
                    ans = ans + st.top();                   // append popped operator to output
                    st.pop();                               // remove it from stack
                }
                st.push(s[i]);                              // push current operator onto stack
            }
        }
        while(!st.empty()) {                                // after scanning, empty remaining stack
            ans = ans + st.top();                           // append each leftover operator to output
            st.pop();                                       // remove it from stack
        }
        return ans;                                         // return final postfix expression
    }
    
};



int main() {
    Solution obj;

    string s;
    cin >> s;

    cout << obj.infixToPostfix(s);

    return 0;
}




// Time Complexity: O(N)
// Space Complexity: O(N)