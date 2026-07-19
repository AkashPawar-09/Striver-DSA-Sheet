/*

Input: s = "(()())(())"
Output: "()()()"
Explanation: 
The input string is "(()())(())", with primitive decomposition "(()())" + "(())".
After removing outer parentheses of each part, this is "()()" + "()" = "()()()".


Input: s = "(()())(())(()(()))"
Output: "()()()()(())"
Explanation: 
The input string is "(()())(())(()(()))", with primitive decomposition "(()())" + "(())" + "(()(()))".
After removing outer parentheses of each part, this is "()()" + "()" + "()(())" = "()()()()(())".


Input: s = "()()"
Output: ""
Explanation: 
The input string is "()()", with primitive decomposition "()" + "()".
After removing outer parentheses of each part, this is "" + "" = "".

*/


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string removeOuterParentheses(string s) {
        string ans = "";                    // Stores final result
        int balance = 0;                    // Current nesting depth

        for (char ch : s) {                 // Traverse every character in given string 

            if (ch == '(') {                // Opening bracket

                if (balance > 0){           // if balanace is positive
                    ans = ans + ch;         // push it back to ans vector
                }

                balance++;                  // increase balance 
            }

            else {                          // if not opening bracket

                balance--;                  // then decrease balance  

                if (balance > 0){           // if balanace is positive
                    ans = ans + ch;         // push it back to ans vector
                }
            }
        }

        return ans;
    }
};

int main() {

    Solution obj;

    string s;
    cin >> s;

    cout << obj.removeOuterParentheses(s);

    return 0;
}


// Time Complexity : 
// Space Complexity : 




/* =======================================================================================================================

DRY RUN CONCEPT :

INDEX   :    0   1   2   3   4   5    6   7   8   9
INPUT   :    (   (   )   (   )   )    (   (   )   )
BALANCE :    1   2   1   2   1   0    1   2   1   0 
                 ↓           ↓            ↓   ↓
               positive balance      positive balance


initially blanace is at 0

If balanace is positive , then add it ans string 

======================================================================================================================= */