#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    int priority(char c) {                                       // returns precedence rank of operator c
        if (c == '^') return 3;                                  // exponentiation has highest priority
        if (c == '*' || c == '/') return 2;                      // multiplication/division next
        if (c == '+' || c == '-') return 1;                      // addition/subtraction lowest
        return 0;                                                // non-operator gets 0
    }
    string infixToPrefix(string &s) {
        reverse(s.begin(), s.end());                             // reverse the whole expression first
        // Swap brackets
        for (char &c : s) {                                      // fix brackets after reversal
            if (c == '(')
                c = ')';                                         // '(' becomes ')' since scan direction flipped
            else if (c == ')')
                c = '(';                                         // ')' becomes '(' for same reason
        }
        stack<char> st;                                          // stack to hold operators and '('
        string postfix;                                          // builds postfix of the reversed string
        for (char c : s) {                                       // scan reversed+swapped string left to right
            // Operand
            if (isalnum(c)) {                                    // if current char is operand
                postfix += c;                                    // append it directly to output
            }
            // Opening bracket
            else if (c == '(') {                                 // if (swapped) opening bracket
                st.push(c);                                      // push it onto stack to mark scope
            }
            // Closing bracket
            else if (c == ')') {                                  // if (swapped) closing bracket
                while (!st.empty() && st.top() != '(') {          // pop and output until '(' is found
                    postfix += st.top();                          // append popped operator to output
                    st.pop();                                     // remove it from stack
                }
                if (!st.empty())
                    st.pop();                                     // discard the matching '(' itself
            }
            // Operator
            else {                                                // current char is an operator
                while (!st.empty() && st.top() != '(' &&          // pop while stack has operator (not '(')
                       (priority(st.top()) > priority(c) ||        // and top has strictly higher priority
                       (priority(st.top()) == priority(c) && c == '^'))) {  // or equal priority with right-assoc '^'
                    postfix += st.top();                          // append popped operator to output
                    st.pop();                                     // remove it from stack
                }
                st.push(c);                                       // push current operator onto stack
            }
        }
        while (!st.empty()) {                                     // empty remaining operators on stack
            postfix += st.top();                                  // append each leftover operator to output
            st.pop();                                              // remove it from stack
        }
        reverse(postfix.begin(), postfix.end());                  // reverse result to get actual prefix
        return postfix;                                           // return final prefix expression
    }
};



int main() {
    Solution obj;

    string s = "h^m^q^(7-4)";

    cout << obj.infixToPrefix(s) << endl;

    return 0;
}




// Time Complexity: O(N)
// Space Complexity: O(N)